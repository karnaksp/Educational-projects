#include "credit_calc.h"

#include "ui_credit_calc.h"

credit_calc::credit_calc(QWidget *parent)
    : QDialog(parent), ui(new Ui::credit_calc) {
  ui->setupUi(this);
  ui->spinBox_term->setMaximum(1188);
}

credit_calc::~credit_calc() { delete ui; }

void add_table(double d, QStandardItemModel *model, int i, int j) {
  QStandardItem *item = new QStandardItem(QString::number(d, 'f', 2));
  model->setItem(i, j, item);
}

void credit_calc::on_comboBox_term_currentIndexChanged(int index) {
  if (index == 0) {
    ui->spinBox_term->setMaximum(1188);
  } else {
    ui->spinBox_term->setMaximum(99);
  }
}

void credit_calc::on_pushButton_clicked() {
  // Создание модели таблицы для отображения результатов
  QStandardItemModel *model = new QStandardItemModel();
  QStringList labels = QObject::tr(
                           "Monthly payment;Payment of the principal debt;"
                           "Payment of interest;Balance of debt")
                           .simplified()
                           .split(";");
  model->setHorizontalHeaderLabels(labels);

  // Получение данных из пользовательского интерфейса
  double amount = ui->doubleSpinBox_credit_sum->value();
  int term = ui->spinBox_term->value();
  double sum_overpayment = 0.0;

  // Преобразование срока кредита в месяцы, если необходимо
  if (ui->comboBox_term->currentText() != "Month") {
    term = term * 12;
  }

  // Вычисление ежемесячной ставки (процентной ставки в месяц)
  double monthlyInterestRate = (ui->doubleSpinBox_bid->value() / 12) / 100;
  double total = 0.0;
  double debt_balance = amount;

  // Расчет аннуитетного платежа
  if (ui->radioButton_annuity->isChecked()) {
    double sum_payment = roundf(amount *
                                (monthlyInterestRate /
                                 (1 - pow(1 + monthlyInterestRate, -term))) *
                                100) /
                         100;
    sum_overpayment = sum_payment * term - amount;
    for (int i = 0; i < term; i++) {
      double overpayment = debt_balance * monthlyInterestRate;
      double payment = roundf((sum_payment - overpayment) * 100) / 100;
      debt_balance -= payment;
      add_table(sum_payment, model, i, 0);
      add_table(payment, model, i, 1);
      add_table(overpayment, model, i, 2);
      add_table(debt_balance, model, i, 3);
    }
  }

  // Расчет дифференцированного платежа
  if (ui->radioButton_different->isChecked()) {
    double payment = amount / term;
    for (int i = 0; i < term; i++) {
      double overpayment = debt_balance * monthlyInterestRate;
      debt_balance = debt_balance - payment;
      sum_overpayment += overpayment;
      double sum_payment = payment + overpayment;

      add_table(sum_payment, model, i, 0);
      add_table(payment, model, i, 1);
      add_table(overpayment, model, i, 2);
      add_table(fabs(debt_balance), model, i, 3);
    }
  }

  // Вычисление итоговой суммы и общей переплаты
  total = sum_overpayment + amount;
  ui->label_overpayment_result->setText(
      QString::number(sum_overpayment, 'f', 2) + " \u20BD");
  ui->label_total_result->setText(QString::number(total, 'f', 2) + " \u20BD");

  // Отображение результатов в виджете таблицы
  ui->tableView->setModel(model);
  ui->tableView->resizeColumnsToContents();
  ui->tableView->show();
}
