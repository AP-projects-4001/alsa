#include "forget_password_client.h"
#include "ui_forget_password_client.h"
#include <QFile>
#include <QMessageBox>
forget_password_client::forget_password_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forget_password_client)
{
    ui->setupUi(this);
}
void forget_password_client::read_file(){
    QFile myfile("Login_client.txt");
    if(!myfile.open(QFile::ReadOnly |QFile::Text))
    {
       qDebug() << " Could not open the file for reading";
       return;
    }
     QTextStream in(&myfile);
     while (!in.atEnd())
     {
            QString myText = in.readLine();
            QStringList List = myText.split(',');
                nameVect.push_back(List[0]);
                password_vect.push_back(List[1]);
                address_vect.push_back(List[2]);
                phoneNumber.push_back(List[3]);
                card_numberVect.push_back(List[4]);
                CVV2_Vect.push_back(List[5]);
                money_Vect.push_back(List[6]);

       }
         myfile.close();
}
void forget_password_client::Write_to_file(){
    QFile file("Login_client.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
      qDebug() << " Could not open file for writing";
      return;
    }
    QTextStream out(&file);
    int i=0;
    while (i < nameVect.size())
    {
        out <<nameVect[i]<<','
              <<password_vect[i]<<','
              <<address_vect[i]<<','
              <<phoneNumber[i]<<','
              <<card_numberVect[i]<<','
              <<CVV2_Vect[i]<<','
              <<money_Vect[i]<<'\n';
        i++;
    }
    file.flush();
    file.close();
}
forget_password_client::~forget_password_client()
{
    delete ui;
}


void forget_password_client::on_buttonBox_accepted()
{
       read_file();
        int i=0;
        bool isval = false;
         for(i ; i < nameVect.size() ; i++){
            if(nameVect[i] == ui->lineEdit->text()){
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
           password_vect.replace(i,ui->lineEdit_2->text());
           Write_to_file();
        }
}

