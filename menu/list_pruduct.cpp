#include "list_pruduct.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QFile>

int list_pruduct::number = 0;

QGroupBox* list_pruduct::createGroup()
{
    number++;

    QFile inputFile("pruduct.txt");
    QStringList split;

    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);

       for (int i = 0; i != number; i++)
       {
          QString line = in.readLine();
          split = line.split(",");
       }

       inputFile.close();
    }

    QGroupBox *groupBox = new QGroupBox(split[0]);

    QVBoxLayout* button_layout = new QVBoxLayout();
    QVBoxLayout* price_layout = new QVBoxLayout();
    QHBoxLayout* main_layout = new QHBoxLayout();

    QLabel* photo = new QLabel();
    QPixmap photo_source{".\\prudoct_picture\\" + QString::number(number) + ".png"};
    photo->setPixmap(photo_source.scaled(100,100));

    int fprice = split[1].toInt() * (100 - split[9].toInt());

    QLineEdit* price = new QLineEdit(split[1]);
    price->setDisabled(true);

    QLineEdit* finally_price = new QLineEdit(QString::number(fprice / 100));
    finally_price->setReadOnly(true);

    QLabel* discount = new QLabel(split[9]+"%");

    if(split[9] == "0")
    {
        discount->setVisible(false);
        price->setVisible(false);
    }

    QString id = split[8];

    buy = new QPushButton{"افزودن به سبد خرید"};
    connect(buy,&QPushButton::clicked,[this, id] { on_buy_button(id); });

    detail = new QPushButton{"جزئیات محصول"};
    connect(detail,&QPushButton::clicked,[this, id] { on_detail_button(id); });

    report = new QPushButton{"گزارش تخلف"};
    connect(report,&QPushButton::clicked,[this, id] { on_report_button(id); });

    buttons.push_back(buy);
    buttons.push_back(detail);
    buttons.push_back(report);

    price->setMaximumWidth(60);
    price->setFixedWidth(60);

    finally_price->setMaximumWidth(60);
    finally_price->setFixedWidth(60);
    finally_price->setAlignment(Qt::AlignCenter);

    discount->setAlignment(Qt::AlignCenter);
    discount->setStyleSheet("QLabel { background-color : red; color : white; font-size:20px;}");

    button_layout->addWidget(buy);
    button_layout->addWidget(detail);
    button_layout->addWidget(report);

    price_layout->addWidget(price);
    price_layout->addWidget(discount);
    price_layout->addWidget(finally_price);

    main_layout->addWidget(photo);
    main_layout->addLayout(price_layout);
    main_layout->addLayout(button_layout);

    main_layout->setSizeConstraint(QLayout::SetFixedSize);
    groupBox->setLayout(main_layout);

    return groupBox;
}

list_pruduct::list_pruduct(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("لیست محصولات"));
    setFixedWidth(1000);
    setMaximumWidth(1000);

    QGridLayout *grid = new QGridLayout;
    int count = 0;
    number = 0;

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 3; j++)
        {
            if(count == countlines("pruduct.txt"))
                break;

            grid->addWidget(createGroup(), i, j);
            count ++;
        }

    setLayout(grid);
}

void list_pruduct::on_buy_button(QString id)
{
    /*----------------------------------------*/
}

void list_pruduct::on_detail_button(QString id)
{
    /*----------------------------------------*/
}

void list_pruduct::on_report_button(QString id)
{
    /*----------------------------------------*/
}

int list_pruduct::countlines(QString fname)
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

list_pruduct::~list_pruduct()
{
    for(int i = 0; i < buttons.length(); i++)
        delete buttons[i];

    buttons.clear();
}
