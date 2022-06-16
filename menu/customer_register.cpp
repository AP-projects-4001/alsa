#include "customer_register.h"
#include "ui_customer_register.h"
#include <QFile>
customer_register::customer_register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customer_register)
{
    ui->setupUi(this);
}

customer_register::~customer_register()
{
    delete ui;
}
void customer_register::read_file(){
    QFile myfile("shope_customer.txt");
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
            NameVect.push_back(List[0]);
            BankCardNumber_vect.push_back(List[1]);
            CVV2_card_vect.push_back(List[2]);
            supply_vect.push_back(List[3]);
         }
         myfile.close();
}
void customer_register::write_to_file(){
    QFile file("shope_customer.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
      qDebug() << " Could not open file for writing";
      return;
    }
    QTextStream out(&file);
    int i=0;
    while (i < NameVect.size())
    {
        out << NameVect[i]<<','
        <<BankCardNumber_vect[i]<<','
        <<CVV2_card_vect[i]<<','
        <<supply_vect[i]<<Qt::endl;
        i++;
    }
    file.flush();
    file.close();
}
void customer_register::on_buttonBox_accepted()
{
    read_file();
    QString Difalt = "1000000";// پول دیفالت برای هر فروشنده
    NameVect.push_back(ui->lineEdit->text());
    BankCardNumber_vect.push_back(ui->lineEdit_2->text());
    CVV2_card_vect.push_back(ui->lineEdit_3->text());
    supply_vect.push_back(Difalt);
    write_to_file();
}

