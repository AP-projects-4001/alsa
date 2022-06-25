#include "client_meno.h"
#include "ui_client_meno.h"
#include <QMessageBox>

client_meno::client_meno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client_meno)
{

}

client_meno::~client_meno()
{
    delete ui;
}

void client_meno::on_pushButton_clicked()
{
    list_pruduct* temp = new list_pruduct{this};
    connect(this, SIGNAL(sendUserName(QString)), temp, SLOT(getUserName(QString)));

    temp->show();
    emit sendUserName(username);
}

void client_meno::on_pushButton_4_clicked()
{
    QMessageBox::information(this,"a",username);
    close();
}

void client_meno::getUserName(QString str)
{
    username = str;
    ui->setupUi(this);
    setWindowTitle("صفحه خریدار");
}

