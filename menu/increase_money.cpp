#include "increase_money.h"
#include "ui_increase_money.h"
#include <qpixmap.h>
#include <QMessageBox>
#include <QFile>
increase_money::increase_money(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::increase_money)
{
    ui->setupUi(this);
    QPixmap pix("E:/increas/Increases_money/image.jfif");
    int w = ui->label->width();
    int h = ui->label_2->height();
    ui->label->setPixmap(pix.scaled(w,h));
}
increase_money::~increase_money()
{
    delete ui;
}
void increase_money::Read_file_cus(){
    QFile myfile("Login_customer.txt");
    if(!myfile.open(QFile::ReadOnly |QFile::Text))
    {
       qDebug() << " Could not open the file for reading";
       return;
    }
    QTextStream in(&myfile);
    while (!in.atEnd()){
             QString myText = in.readLine();
             QStringList List = myText.split(',');
             Name_vect_cus.push_back(List[0]);
             Password_vect_cus.push_back(List[1]);
            Card_Bank_vect_cus.push_back(List[2]);
            CVV2_of_card_cus.push_back(List[3]);
            Supply_Vect_cus.push_back(List[4]);
            Block.push_back(List[5]);
         }
         myfile.close();
}
void increase_money::read_file(){
    QFile myfile("Login_client.txt");
    if(!myfile.open(QFile::ReadOnly |QFile::Text))
    {
       qDebug() << " Could not open the file for reading";
       return;
    }
    QTextStream in(&myfile);
    while (!in.atEnd()){
            QString myText = in.readLine();
            QStringList List = myText.split(',');
            Name_vect.push_back(List[0]);
            Password_vect.push_back(List[1]);
             Address_vect.push_back(List[2]);
            Phonenumber_vect.push_back(List[3]);
            Card_Bank_vect.push_back(List[4]);
            CVV2_of_card.push_back(List[5]);
            Supply_Vect.push_back(List[6]);
         }
         myfile.close();
}
void increase_money::Read_file(){
    QFile myfile("buylist.txt");
    if(!myfile.open(QFile::ReadOnly |QFile::Text))
    {
       qDebug() << " Could not open the file for reading";
       return;
    }
    QTextStream in(&myfile);
    while (!in.atEnd()){
            QString myText = in.readLine();
            QStringList List = myText.split(',');
            customer_name.push_back(List[0]);
            client_name.push_back(List[1]);
            price.push_back(List[2]);
            counter.push_back(List[3]);
         }
         myfile.close();
}
void increase_money:: Read_file_history(){
    QFile myfile("history.txt");
    if(!myfile.open(QFile::ReadOnly |QFile::Text))
    {
       qDebug() << " Could not open the file for reading";
       return;
    }
    QTextStream in(&myfile);
    while (!in.atEnd()){
            QString myText = in.readLine();
            QStringList List = myText.split(',');
            customer_name_his.push_back(List[0]);
            client_name_his.push_back(List[1]);
            price_his.push_back(List[2]);
            counter_his.push_back(List[3]);
         }
         myfile.close();
}
void increase_money::Write_to_file(){
    QFile file("Login_client.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
      qDebug() << " Could not open file for writing";
      return;
    }
    QTextStream out(&file);
    int i=0;
    while (i < Name_vect.size())
    {
        out << Name_vect[i]<<','
        <<Password_vect[i]<<','
        <<Address_vect[i]<<','
        <<Phonenumber_vect[i]<<','
        <<Card_Bank_vect[i]<<','
        <<CVV2_of_card[i]<<','
        <<Supply_Vect[i]
        <<Qt::endl;
        i++;
    }
    file.flush();
    file.close();
}
void increase_money::Write_to_file_cus(){
    QFile file("Login_customer.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
      qDebug() << " Could not open file for writing";
      return;
    }
    QTextStream out(&file);
    int i=0;
    while (i < Name_vect.size())
    {
        out << Name_vect_cus[i]<<','
        <<Password_vect_cus[i]<<','
        <<Card_Bank_vect_cus[i]<<','
        <<CVV2_of_card_cus[i]<<','
        <<Supply_Vect_cus[i]<<','
        <<Block[i]<<','
        <<Qt::endl;
        i++;
    }
    file.flush();
    file.close();
}
void increase_money::Write_to_file_history(){
    QFile file("history.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
      qDebug() << " Could not open file for writing";
      return;
    }
    QTextStream out(&file);
    int i=0;
    while (i <customer_name_his.size())
    {
        out << customer_name_his[i]<<','
        <<client_name_his[i]<<','
        <<price_his[i]<<','
        <<counter_his[i]
        <<Qt::endl;
        i++;
    }
    file.flush();
    file.close();
}
void increase_money::Write_to_file_remove(){
    QFile file("buylist.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
      qDebug() << " Could not open file for writing";
      return;
    }
    QTextStream out(&file);
    int i=0;
    while (i < customer_name_remove.size())
    {
        out << customer_name_remove[i]<<','
        <<client_name_remove[i]<<','
        <<price_remove[i]<<','
        <<counter_remove[i]
        <<Qt::endl;
        i++;
    }
    file.flush();
    file.close();
}
void increase_money::add_money(QString money)
{
    ui->lineEdit_4->setText(money);
}
void increase_money::on_buttonBox_accepted()
{

    read_file();
    bool is_valid = false;
    int i = 0;
    for(i ; i < Name_vect.size() ; i++){
        if(Card_Bank_vect[i] == ui->lineEdit->text()){
            is_valid = true;
            break;
        }

    }
    if(!is_valid)
    {
        int ret;
        QMessageBox msgBox;
        msgBox.setText("این شماره کارت وجود ندارد!!!!");
        ret = msgBox.exec();
        return;
    }
    if(ui->lineEdit_2->text() == CVV2_of_card[i]&&
             ui->lineEdit_3->text() == Password_vect[i])
        {
             check_buy = true;
             int M = Supply_Vect[i].toInt();
             M = M - ui->lineEdit_4->text().toInt();
             Supply_Vect.replace(i,QVariant(M).toString());
             Write_to_file();
             int ret;
             QMessageBox msgBox;
             msgBox.setText("خرید با موفقیت انجام شد :)))))");
             ret = msgBox.exec();
              increas_money_of_customer();
             return;
        }
    else{
        int ret;
        QMessageBox msgBox;
        msgBox.setText("رمز یا سی وی وی 2 اشتباه است !!!! ");
        ret = msgBox.exec();
        return;
    }
}
void increase_money::add_item(QString money,QString user){
    ui->lineEdit_4->setText(money);
    username = user;
}
void increase_money::increas_money_of_customer()
{
    if(check_buy){
         Read_file();
         Read_file_cus();
         Read_file_history();
         for(int i = 0 ; i < customer_name.size() ; i++)
         {
             if(client_name[i] == username){
                 customer_name_his.push_back(customer_name[i]);
                 client_name_his.push_back(client_name[i]);
                 price_his.push_back(price[i]);
                 counter_his.push_back(counter[i]);
                 for(int j = 0 ; j <Name_vect_cus.size() ; j++ ){
                 if(customer_name[i] == Name_vect_cus[j]){
                     int M = Supply_Vect_cus[j].toInt() + price[j].toInt();
                     Supply_Vect_cus.replace(j,QVariant(M).toString());
                   }
                 }
             }else{
                 customer_name_remove.push_back(customer_name[i]);
                 client_name_remove.push_back(client_name[i]);
                 price_remove.push_back(price[i]);
                 counter_remove.push_back(counter[i]);
             }
         }
         Write_to_file_cus();
         Write_to_file_history();
         Write_to_file_remove();
    }
}
