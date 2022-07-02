#include "admin.h"
#include "ui_admin.h"
#include "block_user.h"
#include"unblock.h"
#include"chenge_information.h"
#include"delete_user.h"
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

