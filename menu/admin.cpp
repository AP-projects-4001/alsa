#include "admin.h"
#include "ui_admin.h"
#include "block_user.h"
#include"unblock.h"
#include"chenge_information.h"
#include"delete_user.h"
#include <QMessageBox>
#include "list_pruduct.h"
#include <QFile>
#include<QUrl>
#include<QDesktopServices>
Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_clicked()
{
    block_user *d = new block_user(this);
    d->show();
}


void Admin::on_pushButton_2_clicked()
{
    unblock* d = new unblock(this);
    d->show();
}


void Admin::on_pushButton_3_clicked()
{
    chenge_information* d = new chenge_information(this);
    d->show();
}


void Admin::on_pushButton_4_clicked()
{
   delete_user* d = new delete_user(this);
   d->show();
}

void Admin::on_pushButton_5_clicked()
{
    QFile file("history.txt");
    int line_count = 0;
    QString line;
    QTextStream in(&file);

    file.open(QIODevice::ReadWrite);

    while( !in.atEnd())
    {
        line=in.readLine();
        line_count++;
    }

    file.close();

    if(line_count == 0)
    {
        QMessageBox::warning(this,"اخطار","تاریخچه تراکنش ها خالی است");
        return;
    }

    history* temp = new history();
    temp->show();
    connect(this, SIGNAL(sendUserName(QString)), temp, SLOT(getsId(QString)));
    emit sendUserName("admin");
}

void Admin::on_pushButton_8_clicked()
{
    QMessageBox::information(this,"خدانگهدار","خسته نباشید!");
    close();
}
void Admin::on_pushButton_6_clicked()
{
    list_pruduct* temp = new list_pruduct{this};
    connect(this, SIGNAL(sendUserName(QString)), temp, SLOT(getUserName(QString)));

    temp->show();
    emit sendUserName("admin");
}


void Admin::on_pushButton_9_clicked()
{
    QString link = "https://edbazar.com/electronic/CategoryPages/Index/1/"
                   "%D9%84%DB%8C%D8%B3%D8%AA-%D9%82%DB%8C"
                   "%D9%85%D8%AA-%D9%85%D8%AD%""D8%B5%D9%88%D9"
                   "%84%D8%A7%D8%AA-%""D8%AF%DB%8C%D8%AC%DB%8C%D8%AA%D8%A7%D9%84";
    QDesktopServices::openUrl(QUrl(link));
}

