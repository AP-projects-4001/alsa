#include "creat_new_password.h"
#include "ui_creat_new_password.h"
#include <QMessageBox>
#include <QFile>
QVector <QString> Name_vect;
QVector <QString> Phonenumber_vect;
QVector <QString> Address_vect;
QVector <QString> Password_vect;
creat_new_password::creat_new_password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creat_new_password)
{
    ui->setupUi(this);
}

creat_new_password::~creat_new_password()
{
    delete ui;
}

void creat_new_password::Read_file(){
    QFile myfile("shope.txt");
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
            Name_vect.push_back(List[0]);
            Phonenumber_vect.push_back(List[1]);
            Address_vect.push_back(List[2]);
            Password_vect.push_back(List[3]);
         }
         myfile.close();
}
void creat_new_password::on_buttonBox_accepted()
{
    if(ui->lineEdit->text() != ui->lineEdit_2->text()){
        int ret;
        QMessageBox msgBox;
        msgBox.setText("رمز جدید با تکرار آن همخوانی ندارد...!!");
        ret = msgBox.exec();
    }
    else{

    }
}

