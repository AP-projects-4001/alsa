#include "admin.h"
#include "ui_admin.h"
#include "block_user.h"
#include"unblock.h"
#include"chenge_information.h"
#include"delete_user.h"
#include <QMessageBox>

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