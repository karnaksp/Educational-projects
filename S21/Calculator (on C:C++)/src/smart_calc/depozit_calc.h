#ifndef DEPOZIT_CALC_H
#define DEPOZIT_CALC_H

#include <QDate>
#include <QDialog>
#include <QString>
#include <QVector>
#include <cmath>
#include <vector>

namespace Ui {
class depozit_calc;
}

class depozit_calc : public QDialog {
  Q_OBJECT

 public:
  explicit depozit_calc(QWidget *parent = nullptr);
  ~depozit_calc();

  // Объявление структуры Transaction
  struct Transaction {
    QDate date;
    double interest;
    double balanceChange;
    double payout;
    double balance;
  };

  // Объявление структуры DepositInfo
  struct DepositInfo {
    QDate date;
    double amount;
    QString type;  // "One-time", "Month", or "Year"
  };

  // Объявление структуры WithdrawalInfo
  struct WithdrawalInfo {
    QDate date;
    double amount;
    QString type;
  };

 private slots:
  void addReplenishment();
  void addWithdrawal();
  void calculateDeposit();
  void updateScheduleTable(const std::vector<Transaction> &schedule);
  double calculateTransaction(Transaction &transaction,
                              const QVector<DepositInfo> &replenishments,
                              const QVector<WithdrawalInfo> &withdrawals,
                              bool capitalization, double interest, double tax,
                              double S0, std::vector<Transaction> &schedule,
                              double totalAmount, double tmp_earn,
                              double totalInterest_tmp);
  std::vector<Transaction> CalculateDeposits(
      double amount, int term, int termMonth, double interestRate,
      double taxRate, bool capitalization, int frequency,
      const QVector<DepositInfo> &replenishments,
      const QVector<WithdrawalInfo> &withdrawals, double totalInterest_tmp);

 private:
  Ui::depozit_calc *ui;
  QVector<DepositInfo>
      replenishments;  // Вектор для хранения информации о пополнениях
  QVector<WithdrawalInfo>
      withdrawals;  // Вектор для хранения информации о выводах
};

#endif  // DEPOSIT_CALC_H
