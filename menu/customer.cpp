#include "customer.h"
#include "ui_customer.h"
#include "customer_register.h"
#include <QFile>
#include <QMessageBox>
customer::customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customer)
{
    ui->setupUi(this);
}

customer::~customer()
{
    delete ui;
}
void customer::read_file(){
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
            Name__Vect.push_back(List[0]);
            BankCardNumber__vect.push_back(List[1]);
            CVV2_card__vect.push_back(List[2]);
            supply__vect.push_back(List[3]);
         }
         myfile.close();
}
void customer::on_buttonBox_accepted()
{
    read_file();
    if(ui->lineEdit_2->text() == "forooshande"){
        QString name = ui->lineEdit->text();
        int i = 0;
        bool is_valid = false;
        for(i ; i < Name__Vect.size() ; i++){
            if(Name__Vect[i]==name){
                is_valid = true;
                break;
            }
        }
        if(!is_valid){
            int ret;
            QMessageBox msgBox;
            msgBox.setText("نام کاربری وارد شده غلط است !!!");
            ret = msgBox.exec();
            return;
        }
        else
        {
            /******************************************/
        }
    }
    else{
        int ret;
        QMessageBox msgBox;
        msgBox.setText("رمز وارد شده غلط است !!!");
        ret = msgBox.exec();
        return;
    }
}


void customer::on_pushButton_clicked()
{
    customer_register *d = new customer_register(this);
    d->show();
}

