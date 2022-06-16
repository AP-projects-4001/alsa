#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>
admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_buttonBox_accepted()
{
    if(ui->lineEdit->text() == "Admin" && ui->lineEdit_2->text() == "Admin"){
       /**************************************/
    }
    else{
        int ret;
        QMessageBox msgBox;
        msgBox.setText("نام کاربری یا رمز عبور اشتباه است !!!");
        ret = msgBox.exec();
    }
}

