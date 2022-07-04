#include "custumer_menu.h"
#include "ui_custumer_menu.h"
#include "add_product.h"
#include <QMessageBox>
#include "list_pruduct.h"
#include "history.h"
#include <QFile>

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
    QFile myfile("Login_customer.txt");
    if(!myfile.open(QFile::ReadOnly |QFile::Text))
    {
       return;
    }

    QTextStream  in(&myfile);
    while (!in.atEnd())
    {
        QString myText = in.readLine();
        QStringList List = myText.split(',');
        if(str == List[1])
        {
            username = List[0];
            break;
        }
    }

    ui->setupUi(this);
    setWindowTitle("صفحه فروشنده");
}

void custumer_menu::on_pushButton_clicked()
{
    list_pruduct* temp = new list_pruduct{this};
    connect(this, SIGNAL(sendUserName(QString)), temp, SLOT(getUserName(QString)));

    temp->show();
    emit sendUserName(username);
}


void custumer_menu::on_pushButton_3_clicked()
{
    history* temp = new history{this};
    connect(this, SIGNAL(sendUserName(QString)), temp, SLOT(getsId(QString)));
    temp->show();
    emit sendUserName(username);
}

