#include "client_meno.h"
#include "ui_client_meno.h"

client_meno::client_meno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client_meno)
{
    ui->setupUi(this);
}

client_meno::~client_meno()
{
    delete ui;
}

void client_meno::on_pushButton_clicked()
{
    list_pruduct* temp = new list_pruduct{this};
    temp->show();
}

void client_meno::on_pushButton_4_clicked()
{
    increase_money* temp = new increase_money{this};
    temp->show();
}

