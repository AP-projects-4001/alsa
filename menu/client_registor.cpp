#include "client_registor.h"
#include "ui_client_registor.h"
#include <QFile>
client_registor::client_registor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client_registor)
{
    ui->setupUi(this);
}
void client_registor::read_file(){
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
void client_registor::Write_to_file(){
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
client_registor::~client_registor()
{
    delete ui;
}

void client_registor::on_buttonBox_accepted()
{
    read_file();
    nameVect.push_back(ui->lineEdit->text());
    password_vect.push_back(ui->lineEdit_2->text());
    address_vect.push_back(ui->lineEdit_3->text());
    phoneNumber.push_back(ui->lineEdit_4->text());
    card_numberVect.push_back(ui->lineEdit_5->text());
    CVV2_Vect.push_back(ui->lineEdit_6->text());
    money_Vect.push_back("1000000");
    Write_to_file();
}

