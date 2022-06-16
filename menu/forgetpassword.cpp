#include "forgetpassword.h"
#include "ui_forgetpassword.h"
#include <QFile>
#include <QMessageBox>
forgetpassword::forgetpassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forgetpassword)
{
    ui->setupUi(this);
}

forgetpassword::~forgetpassword()
{
    delete ui;
}
void forgetpassword::read_file(){
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
void forgetpassword::Write_to_file(){
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
void forgetpassword::on_buttonBox_accepted()
{
    read_file();
    int i=0;
    bool isval = false;
    QString check = ui->lineEdit->text();
    for(i ; i < Name_vect.size() ; i++){
        if(Name_vect[i] == check){
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
       Password_vect.replace(i,ui->lineEdit_2->text());
       Write_to_file();
    }
}
void forgetpassword::ADD_item(QString name){

}
