#include "add_product.h"
#include "ui_add_product.h"
#include <QFileDialog>
#include <QMessageBox>

Add_Product::Add_Product(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Product)
{
    ui->setupUi(this);

    ui->lineEdit_2->setValidator( new QIntValidator(0, 999999999, this) );
}

Add_Product::~Add_Product()
{
    delete ui;
}

void Add_Product::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "لطفا تصویر محصول مورد نظر را انتخاب کنید", "/", tr("Image Files (*.png *.jpg *.bmp)"));

    if (fileName.isEmpty())
        return;

    imagePixmap.load(fileName);
    ui->label->setPixmap(imagePixmap);
}

int Add_Product::countlines(QString fname)
{
    QFile file(fname);
    int line_count = 0;
    QString line[100];
    QTextStream in(&file);

    file.open(QIODevice::ReadWrite);

    while( !in.atEnd())
    {
        line[line_count]=in.readLine();
        line_count++;
    }

    file.close();
    return line_count;
}

void Add_Product::on_buttonBox_accepted()
{
    QString filename= "pruduct.txt";

    QDir dir;
    dir.mkdir(QString(".\\prudoct_picture"));
    imagePixmap.save(QString(".\\prudoct_picture\\") + QString::number(countlines(filename)+1) + ".png");

    QFile file(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
    QTextStream stream( &file );

    QString sub = ui->lineEdit->text();
    QString price = ui->lineEdit_2->text();
    QString year = QString::number(ui->spinBox_2->value());
    QString number = QString::number(ui->spinBox->value());
    QString color = ui->lineEdit_4->text();
    QString made = ui->lineEdit_5->text();
    QString categ = ui->comboBox->currentText();
    QString other = ui->plainTextEdit->toPlainText();

    stream << sub << "," << price << "," << year << "," << number << ","
           << color << "," << made << "," << categ << "," << other << ","
           << countlines(filename)+1 << "\n";

    file.close();
}

void Add_Product::getUserName(QString str)
{
    setWindowTitle("افزودن محصول"+str);
}
