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
void forget_pasword_customer::read_file(){
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
void forget_pasword_customer::Write_to_file(){
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
forget_pasword_customer::~forget_pasword_customer()
{
    delete ui;
}

void forget_pasword_customer::on_buttonBox_accepted()
{
    read_file();
    bool isval = false;
    int i = 0;
    for(i  ; i < nameVect.size() ; i++ ){
        if(ui->lineEdit->text() == nameVect[i]){
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

