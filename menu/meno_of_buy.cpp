#include "meno_of_buy.h"
#include "ui_meno_of_buy.h"

meno_of_buy::meno_of_buy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::meno_of_buy)
{
    ui->setupUi(this);
}

meno_of_buy::~meno_of_buy()
{
    delete ui;
}
