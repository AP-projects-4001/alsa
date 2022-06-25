#include "registor.h"
#include "ui_registor.h"
#include <QMessageBox>
#include <QFile>
Registor::Registor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registor)
{
    ui->setupUi(this);
}
void Registor::read_file(){
    QFile myfile("Login_customer.txt");
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
                card_numberVect.push_back(List[2]);
                CVV2_Vect.push_back(List[3]);
                money_Vect.push_back(List[4]);

       }
         myfile.close();
}
void Registor::Write_to_file(){
    QFile file("Login_customer.txt");
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
             <<card_numberVect[i]<<','
             <<CVV2_Vect[i]<<','
             <<money_Vect[i]<<'\n';
        i++;
    }
    file.flush();
    file.close();
}
Registor::~Registor()
{
    delete ui;
}

void Registor::on_buttonBox_accepted()
{
       QString money_ = "1000000";
       read_file();
       bool isvalid = false;
       for(int i =0 ; i < nameVect.size() ; i++){
           if(password_vect[i]==ui->lineEdit_3->text()){
               isvalid  = true;
               break;
           }
       }
       if(!isvalid){
           card_numberVect.push_back(ui->lineEdit->text());
           CVV2_Vect.push_back(ui->lineEdit_2->text());
           password_vect.push_back(ui->lineEdit_3->text());
           nameVect.push_back(ui->lineEdit_4->text());
           money_Vect.push_back(money_);
           Write_to_file();
       }
       else{
           QMessageBox msgBox;
          msgBox.setText("رمز تکراری است!!!!!");
          int ret = msgBox.exec();
       }
}

