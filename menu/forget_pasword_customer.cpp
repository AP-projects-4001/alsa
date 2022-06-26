#include "forget_pasword_customer.h"
#include "ui_forget_pasword_customer.h"
#include <QMessageBox>
#include <QFile>
forget_pasword_customer::forget_pasword_customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forget_pasword_customer)
{
    ui->setupUi(this);
}
forget_pasword_customer::~forget_pasword_customer()
{
    delete ui;
}
void forget_pasword_customer::on_buttonBox_accepted()
{
    Read_file();
    bool isval = false;
    int i = 0;
    for(i  ; i < name.size() ; i++ ){
        if(ui->lineEdit->text() == name[i]){
            isval = true;
            break;
        }
    }
    if(!isval){
        int ret;
        QMessageBox msgBox;
        msgBox.setText("این کاربر وجود ندارد !!!!!");
         ret = msgBox.exec();
    }
    else{
          password.replace(i,ui->lineEdit_2->text());
          Write_to_file();
       }
}

