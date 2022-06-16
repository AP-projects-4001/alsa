#ifndef INCREASE_BANK_CARD_BALANCE_H
#define INCREASE_BANK_CARD_BALANCE_H

#include <QDialog>

namespace Ui {
class Increase_bank_card_balance;
}

class Increase_bank_card_balance : public QDialog
{
    Q_OBJECT

public:
    explicit Increase_bank_card_balance(QWidget *parent = nullptr);
    ~Increase_bank_card_balance();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Increase_bank_card_balance *ui;
};

#endif // INCREASE_BANK_CARD_BALANCE_H
