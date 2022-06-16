#include "increase_bank_card_balance.h"
#include "ui_increase_bank_card_balance.h"
#include "increase_money.h"
Increase_bank_card_balance::Increase_bank_card_balance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Increase_bank_card_balance)
{
    ui->setupUi(this);
}

Increase_bank_card_balance::~Increase_bank_card_balance()
{
    delete ui;
}

void Increase_bank_card_balance::on_pushButton_2_clicked()
{
    increase_money* d = new increase_money(this);
    d->show();
}


void Increase_bank_card_balance::on_pushButton_clicked()
{

}

