#include "admin.h"
#include "ui_admin.h"
#include "block_user.h"
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
