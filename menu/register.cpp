#include "register.h"
#include "ui_register.h"
#include <QFile>
Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}
void Register::Read_from_file(){
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
           name_vect.push_back(List[0]);
           phonenumber_vect.push_back(List[1]);
           address_vect.push_back(List[2]);
           password_vect.push_back(List[3]);
           CardBank_vect.push_back(List[4]);
           CVV2_ofCard_vect.push_back(List[5]);
           Supply_Vect.push_back(List[6]);
      }
      myfile.close();
}
void Register::Write_to_file(){
    QFile file("shope_client.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
      qDebug() << " Could not open file for writing";
      return;
    }
    QTextStream out(&file);
    int i=0;
    while (i < name_vect.size())
    {
        out << name_vect[i]<<','
        <<phonenumber_vect[i]<<','
        <<address_vect[i]<<','
        <<password_vect[i]<<','
        <<CardBank_vect[i]<<','
        <<CVV2_ofCard_vect[i]<<','
        <<Supply_Vect[i]
        <<Qt::endl;
        i++;
    }
    file.flush();
    file.close();
}
void Register::on_buttonBox_accepted()
{
    QString Difalt = "10000000";
    Read_from_file();
    name_vect.push_back(ui->lineEdit->text());
    phonenumber_vect.push_back(ui->lineEdit_2->text());
    address_vect.push_back(ui->lineEdit_3->text());
    password_vect.push_back(ui->lineEdit_4->text());
    CardBank_vect.push_back(ui->lineEdit_5->text());
    CVV2_ofCard_vect.push_back(ui->lineEdit_6->text());
    Supply_Vect.push_back(Difalt);
    Write_to_file();
}

