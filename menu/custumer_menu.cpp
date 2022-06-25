#include "custumer_menu.h"
#include "ui_custumer_menu.h"
#include "add_product.h"
#include <QMessageBox>

custumer_menu::custumer_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::custumer_menu)
{

}

custumer_menu::~custumer_menu()
{
    delete ui;
}

void custumer_menu::on_pushButton_2_clicked()
{
    Add_Product* temp = new Add_Product{this};
    connect(this, SIGNAL(sendUserName(QString)), temp, SLOT(getUserName(QString)));

    temp->show();
    emit sendUserName(username);
}

void custumer_menu::getUserName(QString str)
{
    username = str;
    ui->setupUi(this);
    setWindowTitle("صفحه فروشنده");
}

