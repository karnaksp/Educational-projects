#include "depozit_calc.h"

#include "ui_depozit_calc.h"

depozit_calc::depozit_calc(QWidget *parent)
    : QDialog(parent), ui(new Ui::depozit_calc) {
  ui->setupUi(this);
  connect(ui->pushButton_add_replenishment, &QPushButton::clicked, this,
          &depozit_calc::addReplenishment);
  connect(ui->pushButton_add_withdrawal, &QPushButton::clicked, this,
          &depozit_calc::addWithdrawal);
  connect(ui->pushButton, &QPushButton::clicked, this,
          &depozit_calc::calculateDeposit);

  // Инициализируем таблицу для отображения графика начисления процентов
  ui->tableWidget_schedule->setColumnCount(5);
  QStringList headers;
  headers << "Date"
          << "Interest"
          << "Balance Change"
          << "Payout"
          << "Balance";
  ui->tableWidget_schedule->setHorizontalHeaderLabels(headers);
  ui->tableWidget_schedule->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

depozit_calc::~depozit_calc() { delete ui; }

double depozit_rate(double rate) { return rate * 0.01; }
int depozit_period(int term, int term_month) { return term * term_month; }

double depozit_total(double amount, int term, int term_month,
                     double interest_rate, int frequency, bool capitalization) {
  double interest = depozit_rate(interest_rate), amount_tmp = amount,
         result = 0.0;
  int period = depozit_period(term, term_month);
  if (period >= frequency) {
    for (int i = 1; i <= period; i++) {
      double tmp_earn = 0.0;
      if (frequency == 12) {
        tmp_earn = amount_tmp * interest / 12;
      } else if (frequency == 1) {
        tmp_earn = amount_tmp * interest;
      }
      if (capitalization) amount_tmp += tmp_earn;
      result += tmp_earn;
    }
  }
  return result;
}

double depozit_tax_amount(double total_amount, double tax_rate) {
  double tax = depozit_rate(tax_rate);
  return total_amount * tax;
}

double depozit_end_balance(double total_amount, double amount,
                           double tax_amount) {
  return amount + total_amount - tax_amount;
}

void depozit_calc::addReplenishment() {
  QString dateStr = ui->lineEdit_replenishment_date->text();
  QDate date = QDate::fromString(dateStr, "dd.MM.yyyy");
  double amount = ui->doubleSpinBox_replenishment_amount->value();
  QString type = ui->comboBox_replenishment_type->currentText();
  DepositInfo info;
  info.date = date;
  info.amount = amount;
  info.type = type;
  replenishments.push_back(info);
}

void depozit_calc::addWithdrawal() {
  QString dateStr = ui->lineEdit_withdrawal_date->text();
  QDate date = QDate::fromString(dateStr, "dd.MM.yyyy");
  double amount = ui->doubleSpinBox_withdrawal_amount->value();
  QString type = ui->comboBox_withdrawal_type->currentText();
  WithdrawalInfo info;
  info.date = date;
  info.amount = amount;
  info.type = type;
  withdrawals.push_back(info);
}

void depozit_calc::updateScheduleTable(
    const std::vector<Transaction> &schedule) {
  ui->tableWidget_schedule->setRowCount(schedule.size());
  int row = 0;

  for (const Transaction &transaction : schedule) {
    ui->tableWidget_schedule->setItem(
        row, 0, new QTableWidgetItem(transaction.date.toString("dd.MM.yyyy")));
    ui->tableWidget_schedule->setItem(
        row, 1,
        new QTableWidgetItem(QString::number(transaction.interest, 'f', 2)));
    ui->tableWidget_schedule->setItem(row, 2,
                                      new QTableWidgetItem(QString::number(
                                          transaction.balanceChange, 'f', 2)));
    ui->tableWidget_schedule->setItem(
        row, 3,
        new QTableWidgetItem(QString::number(transaction.payout, 'f', 2)));
    ui->tableWidget_schedule->setItem(
        row, 4,
        new QTableWidgetItem(QString::number(transaction.balance, 'f', 2)));
    row++;
  }
}

double depozit_calc::calculateTransaction(
    Transaction &transaction, const QVector<DepositInfo> &replenishments,
    const QVector<WithdrawalInfo> &withdrawals, bool capitalization,
    double interest, double tax, double S0, std::vector<Transaction> &schedule,
    double totalAmount, double tmp_earn, double totalInterest_tmp) {
  // Учитываем пополнения для текущего периода
  for (const DepositInfo &replenishment : replenishments) {
    if (replenishment.date.year() == transaction.date.year() &&
        replenishment.date.month() == transaction.date.month()) {
      totalAmount += replenishment.amount;
    }
  }

  // Учитываем снятия для текущего периода
  for (const WithdrawalInfo &withdrawal : withdrawals) {
    if (withdrawal.date.year() == transaction.date.year() &&
        withdrawal.date.month() == transaction.date.month()) {
      totalAmount -= withdrawal.amount;
    }
  }

  if (capitalization) {
    totalAmount += tmp_earn;
  }

  double taxableIncome = std::max(0.0, tmp_earn);
  double taxAmount = 0.0;

  if (interest > 0.18) {
    // В РФ доходы по ставке выше 18% в рублях и выше 9% в валюте облагаются
    // налогом в размере 35%
    taxAmount = taxableIncome * 0.035;
  } else if (totalInterest_tmp > S0) {
    // Если налогооблагаемый доход превышает S0, то рассчитываем налог
    taxAmount = taxableIncome * tax;
  }

  transaction.payout = taxAmount;
  transaction.balance = totalAmount - taxAmount;
  transaction.interest = tmp_earn;
  transaction.balanceChange = tmp_earn;

  schedule.push_back(transaction);

  return transaction.balance;
}

std::vector<depozit_calc::Transaction> depozit_calc::CalculateDeposits(
    double amount, int term, int termMonth, double interestRate, double taxRate,
    bool capitalization, int frequency,
    const QVector<DepositInfo> &replenishments,
    const QVector<WithdrawalInfo> &withdrawals, double totalInterest_tmp) {
  std::vector<Transaction> schedule;

  double interest = depozit_rate(interestRate);
  double tax = depozit_rate(taxRate);
  double totalAmount = amount;
  int period = depozit_period(term, termMonth);
  double tmp_earn = 0.0;
  double S0 = 1000000 * tax;
  QDate Currentdate = QDate::currentDate();
  Transaction transaction;
  if (frequency == 1 && termMonth == 1 && period < 12) {
    transaction.date = Currentdate.addMonths(period);
    QDate NextYear = Currentdate.addYears(1);
    long double daysInYear = Currentdate.daysTo(NextYear);
    long double daysInPeriod = Currentdate.daysTo(transaction.date);
    long double percent = interest / daysInYear;
    for (int i = 1; i <= daysInPeriod; i++) {
      tmp_earn += totalAmount * percent;
    }
    calculateTransaction(transaction, replenishments, withdrawals,
                         capitalization, interest, tax, S0, schedule,
                         totalAmount, tmp_earn, totalInterest_tmp);
  } else if (frequency == 1 && termMonth == 1 && period >= 12) {
    QDate EndMonth = Currentdate.addMonths(period);
    period = round(period / 12);

    for (int i = 1; i <= period; i++) {
      QDate NextYear = Currentdate.addYears(1);
      transaction.date = NextYear;
      long double daysInYear = Currentdate.daysTo(NextYear);
      long double percent = interest / daysInYear;
      for (int i = 1; i <= daysInYear; i++) {
        //
        tmp_earn += totalAmount * percent;
      }
      calculateTransaction(transaction, replenishments, withdrawals,
                           capitalization, interest, tax, S0, schedule,
                           totalAmount, tmp_earn, totalInterest_tmp);
      Currentdate = NextYear;
    }
    if (period > 12) {
      transaction.date = EndMonth;
      QDate NextYear = Currentdate.addYears(1);
      long double daysInPeriod = Currentdate.daysTo(EndMonth);
      long double daysInYear = Currentdate.daysTo(NextYear);
      long double percent = interest / daysInYear;
      for (int i = 1; i <= daysInPeriod; i++) {
        //
        tmp_earn += totalAmount * percent;
      }
      calculateTransaction(transaction, replenishments, withdrawals,
                           capitalization, interest, tax, S0, schedule,
                           totalAmount, tmp_earn, totalInterest_tmp);
    }
  } else {
    if (frequency == 1) period = period / 12;
    for (int i = 1; i <= period; i++) {
      QDate NextYear = Currentdate.addYears(1);
      long double daysInYear = Currentdate.daysTo(NextYear);
      long double percent = interest / daysInYear;
      double tmp_earn = 0.0;
      if (frequency == 1) {
        transaction.date = Currentdate.addYears(1);
        for (int i = 1; i <= daysInYear; i++) {
          tmp_earn += totalAmount * percent;
        }
        Currentdate = NextYear;
        totalAmount = calculateTransaction(
            transaction, replenishments, withdrawals, capitalization, interest,
            tax, S0, schedule, totalAmount, tmp_earn, totalInterest_tmp);
      } else if (frequency == 12) {
        QDate NextMonth = Currentdate.addMonths(1);
        transaction.date = NextMonth;
        int daysInMonth = Currentdate.daysTo(NextMonth);
        for (int i = 1; i <= daysInMonth; i++) {
          //
          tmp_earn += totalAmount * percent;
        }
        Currentdate = NextMonth;
        totalAmount = calculateTransaction(
            transaction, replenishments, withdrawals, capitalization, interest,
            tax, S0, schedule, totalAmount, tmp_earn, totalInterest_tmp);
      }
    }
  }
  return schedule;
}

void depozit_calc::calculateDeposit() {
  double Amount = ui->doubleSpinBox_sum_depozit->value();
  int Term = ui->spinBox_term->value();
  int TermMonth = ui->comboBox_term->currentText() == "Year" ? 12 : 1;
  double InterestRate = ui->doubleSpinBox_interest_rate->value();
  double TaxRate = ui->doubleSpinBox_tax_rate->value();
  int Frequency = ui->comboBox_frequency->currentText() == "Year" ? 1 : 12;
  bool Capitalization = ui->checkBox_capitalization->isChecked();

  double totalInterest_tmp = depozit_total(
      Amount, Term, TermMonth, InterestRate, Frequency, Capitalization);

  std::vector<Transaction> schedule = CalculateDeposits(
      Amount, Term, TermMonth, InterestRate, TaxRate, Capitalization, Frequency,
      replenishments, withdrawals, totalInterest_tmp);

  updateScheduleTable(schedule);
  double totalInterest = 0.0;
  double totalTax = 0.0;
  double endBalance = 0.0;

  for (const Transaction &transaction : schedule) {
    totalInterest += transaction.interest;
    totalTax += transaction.payout;
  }

  endBalance = schedule.back().balance;

  if (!Capitalization) {
    endBalance += totalInterest;
    endBalance -= totalTax;
  }

  QString totalInterestStr = QString::number(totalInterest, 'f', 2);
  ui->label_Interest_total->setText(totalInterestStr + " \u20BD");

  QString totalTaxStr = QString::number(totalTax, 'f', 2);
  ui->label_tax_total->setText(totalTaxStr + " \u20BD");

  QString endBalanceStr = QString::number(endBalance, 'f', 2);
  ui->label_total_balance->setText(endBalanceStr + " \u20BD");
}
