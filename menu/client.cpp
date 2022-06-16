#include "client.h"
#include "ui_client.h"
#include "register.h"
#include "forgetpassword.h"
#include "increase_bank_card_balance.h"
#include <QFile>
#include <QMessageBox>
client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
}

client::~client()
{
    delete ui;
}
void client::Read_from_file(){
     QFile myfile("shope_client.txt");
     if(!myfile.open(QFile::ReadOnly |QFile::Text))
     {
         qDebug() << " Could not open the file for reading";
         return;

     }
     QTextStream in(&myfile);
     while (!in.atEnd()){
           QString myText = in.readLine();
           int g=0;
           QStringList List = myText.split(',');
           NAME_VECT.push_back(List[0]);
           PHonenumber_Vect.push_back(List[1]);
           ADDress_Vect.push_back(List[2]);
           PASSWord_Vect.push_back(List[3]);
           Card_Bank_vect.push_back(List[4]);
           CVV2_of_card.push_back(List[5]);
           Supply_Vect.push_back(List[6]);
      }
      myfile.close();
}
void client::on_pushButton_clicked()
{
   Register *d = new Register(this);
   d->show();
}


void client::on_pushButton_2_clicked()
{
    forgetpassword *d = new forgetpassword(this);
    d->show();
}
void client::on_buttonBox_accepted()
{
    Read_from_file();
    bool is_valid1 = false;
    bool is_valid2 = false;
    QString name = ui->lineEdit->text();
    QString pas = ui->lineEdit_2->text();
    for(int i = 0 ; i < NAME_VECT.size() ; i++){
        if(NAME_VECT[i] == name)
            is_valid1 = true;
        if(PASSWord_Vect[i] == pas)
            is_valid2 = true;
    }
    if(is_valid1 == true && is_valid2 == true){
        Increase_bank_card_balance *d = new Increase_bank_card_balance(this);
        d->show();
    }
    else{
        int ret;
        QMessageBox msgBox;
        msgBox.setText("رمز ورود یا نام کاربری اشتباه است..!!!!");
        ret = msgBox.exec();
        return;
    }

}

