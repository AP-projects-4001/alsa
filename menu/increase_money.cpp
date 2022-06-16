#include "increase_money.h"
#include "ui_increase_money.h"
#include "how_much_money.h"
#include <qpixmap.h>
#include <QMessageBox>
#include <QFile>
increase_money::increase_money(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::increase_money)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/digitall home/Documents/shope/logo.jpg");
    int w = ui->label->width();
    int h = ui->label_2->height();
    ui->label->setPixmap(pix.scaled(w,h));
}

increase_money::~increase_money()
{
    delete ui;
}
void increase_money::read_file(){
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
            Name_vect.push_back(List[0]);
            Phonenumber_vect.push_back(List[1]);
            Address_vect.push_back(List[2]);
            Password_vect.push_back(List[3]);
            Card_Bank_vect.push_back(List[4]);
            CVV2_of_card.push_back(List[5]);
            Supply_Vect.push_back(List[6]);
         }
         myfile.close();
}
void increase_money::Write_to_file(){
    QFile file("shope_client.txt");
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
        <<Phonenumber_vect[i]<<','
        <<Address_vect[i]<<','
        <<Password_vect[i]<<','
        <<Card_Bank_vect[i]<<','
        <<CVV2_of_card[i]<<','
        <<Supply_Vect[i]
        <<Qt::endl;
        i++;
    }
    file.flush();
    file.close();
}
void increase_money::on_pushButton_clicked()
{
    how_much_money *d = new how_much_money(this);
    d->show();
    connect(d,SIGNAL(add_money(QString)),this,SLOT(add_money(QString)));
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
        msgBox.setText("شماره کارت وجود خارجی ندارد...!!!");
        ret = msgBox.exec();
        return;
    }
    if(ui->lineEdit_2->text() == CVV2_of_card[i]&&
             ui->lineEdit_3->text() == Password_vect[i])
        {
             int M = Supply_Vect[i].toInt();
             M = M + ui->lineEdit_4->text().toInt();
             Supply_Vect.replace(i,QVariant(M).toString());
             Write_to_file();
             int ret;
             QMessageBox msgBox;
             msgBox.setText("افزایش وجه با موفقیت انجام شد :)))))");
             ret = msgBox.exec();
             return;
        }
    else{
        int ret;
        QMessageBox msgBox;
        msgBox.setText("رمز یا سی وی وی 2 اشتباه است ...!!! ");
        ret = msgBox.exec();
        return;
    }
}

