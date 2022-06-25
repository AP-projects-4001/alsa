#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "registor.h"
#include "client_registor.h"
#include "forget_pasword_customer.h"
#include "forget_password_client.h"
#include <QFile>
#include <QMessageBox>
#include "client_meno.h"
#include "custumer_menu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_2_clicked()
{
       Registor *d = new Registor(this);
       d->show();
}


void MainWindow::on_pushButton_5_clicked()
{
      client_registor *d = new client_registor(this);
      d->show();
}


void MainWindow::on_pushButton_clicked()
{
     forget_pasword_customer *d = new forget_pasword_customer(this);
     d->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    forget_password_client *d = new forget_password_client(this);
    d->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    exit(0);
}
void MainWindow::read_file(QString file_name){
    QFile myfile(file_name);
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
                Password_vect.push_back(List[1]);
       }
         myfile.close();
}
void MainWindow::read_file(){
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
                password.push_back(List[1]);
       }
         myfile.close();
}
void MainWindow::on_pushButton_4_clicked()
{
    if(ui->lineEdit->text() == "admin" && ui->lineEdit_2->text() =="admin" ){
        /***********************FORADDMIN***********************************/
    }
    else if(ui->lineEdit->text() == "customer"){
        read_file("Login_customer.txt");
        bool isvalid = false;
        for(int i = 0 ; i < Password_vect.size() ; i++){
            if(Password_vect[i] == ui->lineEdit_2->text()){
                isvalid = true;
                break;
            }
        }
        if(!isvalid){
               int ret;
               QMessageBox msgBox;
               msgBox.setText("رمز اشتباه است!!!!");
               ui->lineEdit->clear();
               ui->lineEdit_2->clear();
               ret = msgBox.exec();
           }
           else{
                custumer_menu* temp = new custumer_menu();
                temp->show();
                connect(this, SIGNAL(sendUserName(QString)), temp, SLOT(getUserName(QString)));
                emit sendUserName(ui->lineEdit->text());
                close();
           }
    }
    else{
         read_file();
           bool isvalid = false;
           for(int i = 0 ; i < nameVect.size() ; i++){
               if(ui->lineEdit->text() == nameVect [i] && ui->lineEdit_2->text() == password[i]){
                   isvalid = true;
                   break;
               }
           }
           if(!isvalid){
                  QMessageBox::warning(this,"اخطار","رمز یا نام کاربری اشتباه است!!!");
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
              }
              else{
               client_meno* temp = new client_meno();
               temp->show();
               connect(this, SIGNAL(sendUserName(QString)), temp, SLOT(getUserName(QString)));
               emit sendUserName(ui->lineEdit->text());
               close();
              }
     }

}

