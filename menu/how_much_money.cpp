#include "how_much_money.h"
#include "ui_how_much_money.h"
how_much_money::how_much_money(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::how_much_money)
{
    ui->setupUi(this);
}

how_much_money::~how_much_money()
{
    delete ui;
}

void how_much_money::on_buttonBox_accepted()
{
    emit add_money(ui->lineEdit->text());
}

