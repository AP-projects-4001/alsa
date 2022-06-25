#include "product_detail.h"
#include "ui_product_detail.h"
#include <QFile>
#include <QMessageBox>

Product_detail::Product_detail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Product_detail)
{
    ui->setupUi(this);
    setWindowTitle("جزئیات محصول");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

Product_detail::~Product_detail()
{
    delete ui;
}

void Product_detail::on_pushButton_clicked()
{
    close();
}

void Product_detail::getPruductId(QString str)
{
    QFile inputFile("pruduct.txt");
    QStringList split;

    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);

       for (int i = 0; !in.atEnd() ; i++)
       {
          QString line = in.readLine();
          split = line.split(",");

          if(split[8] == str)
             break;
       }

       inputFile.close();
    }

    QPixmap photo_source{".\\prudoct_picture\\" + str + ".png"};
    ui->label->setPixmap(photo_source.scaled(240,240));

    ui->lineEdit->setText(split[0]);
    ui->lineEdit_2->setText(split[1]);
    ui->lineEdit_3->setText(split[9]);
    ui->lineEdit_4->setText(QString::number((split[1].toInt() * (100 - split[9].toInt())) / 100));
    ui->lineEdit_5->setText(split[2]);
    ui->lineEdit_6->setText(split[3]);
    ui->lineEdit_7->setText(split[6]);
    ui->lineEdit_8->setText(split[4]);
    ui->lineEdit_9->setText(split[5]);
    ui->plainTextEdit->setPlainText(split[7]);
}
