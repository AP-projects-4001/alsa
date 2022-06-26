#include "block_user.h"
#include "ui_block_user.h"
#include<QFile>
block_user::block_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::block_user)
{
    ui->setupUi(this);
}

block_user::~block_user()
{
    delete ui;
}
void block_user::read_file(){
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
             block.push_back(List[5]);
       }
         myfile.close();
}
void block_user::Write_to_file(){
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
             <<money_Vect[i]<<','
             <<block[i]<<"\n";
        i++;
    }
    file.flush();
    file.close();
}
void block_user::on_buttonBox_accepted()
{
    QString user_name = ui->lineEdit->text();
    read_file();
    bool check = false;
    for (int i = 0 ; i <nameVect.size() ; i++){
        if(nameVect[i] == user_name){
            check = true;
            block.replace(i,"block");
            break;
        }
    }
    if(check)
        Write_to_file();
}

