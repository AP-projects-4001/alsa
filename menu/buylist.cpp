#include "buylist.h"
#include "ui_buylist.h"
#include <QSpacerItem>
#include <QFile>
#include <QMessageBox>

buylist::buylist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buylist)
{
    ui->setupUi(this);
    setWindowTitle("سبد خرید");
    ui->verticalLayout_2->setAlignment(Qt::AlignCenter);
}

buylist::~buylist()
{
    delete ui;
    delete lay;
//    delete next;
//    delete privious;
//    delete page_number;
//    delete numbers;
//    delete button_lay;

    for(int i = 0; i < spaces.length(); i++)
        delete spaces[i];

    spaces.clear();

    for(int i = 0; i < buttons.length(); i++)
        delete buttons[i];

    buttons.clear();

    for(int i = 0; i < lineedits.length(); i++)
        delete lineedits[i];

    lineedits.clear();

    for(int i = 0; i < labels.length(); i++)
        delete labels[i];

    labels.clear();

    for(int i = 0; i < vlayout.length(); i++)
        delete vlayout[i];

    vlayout.clear();

    for(int i = 0; i < hlayout.length(); i++)
        delete hlayout[i];

    hlayout.clear();

    for(int i = 0; i < spins.length(); i++)
        delete spins[i];

    spins.clear();

    for(int i = 0; i < groups.length(); i++)
        delete groups[i];

    groups.clear();
}

QGroupBox *buylist::createGroup(QString pruduct_id)
{
    setFixedWidth(570);
    setMaximumWidth(570);

    QFile inputFile("pruduct.txt");
    QStringList split;

    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);

       for (int i = 0; ; i++)
       {
          QString line = in.readLine();
          split = line.split(",");

          if(split[8] == pruduct_id)
              break;
       }

       inputFile.close();
    }

    QGroupBox *groupBox = new QGroupBox(split[0]);
    groups.push_back(groupBox);

    QHBoxLayout* main_layout = new QHBoxLayout();
    hlayout.push_back(main_layout);

    QLabel* pl = new QLabel{"قیمت نهایی"};
    labels.push_back(pl);
    int fprice = split[1].toInt() * (100 - split[9].toInt());
    price = new QLineEdit(QString::number(fprice / 100));
    price->setReadOnly(true);
    price->setMaximumWidth(60);
    price->setFixedWidth(60);
    price->setAlignment(Qt::AlignCenter);
    lineedits.push_back(price);

    QLabel* countx = new QLabel{"تعداد"};
    labels.push_back(countx);
    count = new QSpinBox;
    count->setMinimumSize(QSize(50,25));
    spins.push_back(count);
    count->setValue(1);
    count->setRange(1,split[3].toInt());
    connect(count,SIGNAL(valueChanged(int)),this,SLOT(spin_count_changed(int)));

    remove = new QPushButton{"حذف"};
    QString id = pruduct_id;
    connect(remove,&QPushButton::clicked,[this, id] { on_remove_button_clicked(id); });

    buttons.push_back(remove);

    detail = new QPushButton{"جزئیات محصول"};
    //connect(detail,&QPushButton::clicked,[this, id] { on_detail_button(id); });
    buttons.push_back(detail);

    verticalSpacer = new QSpacerItem(60, 0, QSizePolicy::Fixed, QSizePolicy::Fixed);                            // Not sure what to make of this
    ui->verticalLayout_2->addSpacerItem(verticalSpacer);
    spaces.push_back(verticalSpacer);

    main_layout->addWidget(pl);

    main_layout->addWidget(price);

    main_layout->addItem(verticalSpacer);

    main_layout->addWidget(countx);
    main_layout->addWidget(count);
    main_layout->addItem(verticalSpacer);

    main_layout->addWidget(detail);
    main_layout->addWidget(remove);

    main_layout->setSizeConstraint(QLayout::SetFixedSize);
    groupBox->setLayout(main_layout);

    return groupBox;
}

void buylist::on_pushButton_clicked()
{
    for(int i = 0; i < groups.length(); i++)
        delete groups[i];

    groups.clear();
    QSpacerItem* verticalSpacer = new QSpacerItem(500, 500, QSizePolicy::Maximum, QSizePolicy::Maximum);;                             // Not sure what to make of this

    //ui->verticalLayout_2->addWidget(createGroup());
    ui->verticalLayout_2->addSpacerItem(verticalSpacer);

}

void buylist::getId(QString str)
{
    username = str;
    show_list();
}

void buylist::spin_count_changed(int value)
{
    int sum = 0;

    for(int i = 0; i < spins.length(); i++)
    {
        sum += (spins.at(i)->value() * lineedits.at(i)->text().toInt());
    }

    ui->lineEdit_2->setText(QString::number(sum));
}

void buylist::on_remove_button_clicked(QString id)
{
    QVector<QString> lines;
    QFile inputFile("buylist.txt");
    QStringList split;

    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);

       for (int i = 0; !in.atEnd(); i++)
       {
          QString line = in.readLine();

          split = line.split(",");

          if(split[1] == id)
              continue;

          lines.push_back(line);
       }

       inputFile.close();
    }


    QFile file("buylist.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    QTextStream stream( &file );

    for(int i = 0; i < lines.length(); i++)
        stream << lines.at(i) << "\n";

    file.close();

    show_list();
}

void buylist::on_pushButton_2_clicked()
{
    close();
}

void buylist::show_list()
{
    for(int i = 0; i < spaces.length(); i++)
        delete spaces[i];

    spaces.clear();

    for(int i = 0; i < buttons.length(); i++)
        delete buttons[i];

    buttons.clear();

    for(int i = 0; i < lineedits.length(); i++)
        delete lineedits[i];

    lineedits.clear();

    for(int i = 0; i < labels.length(); i++)
        delete labels[i];

    labels.clear();

    for(int i = 0; i < vlayout.length(); i++)
        delete vlayout[i];

    vlayout.clear();

    for(int i = 0; i < hlayout.length(); i++)
        delete hlayout[i];

    hlayout.clear();

    for(int i = 0; i < spins.length(); i++)
        delete spins[i];

    spins.clear();

    for(int i = 0; i < groups.length(); i++)
        delete groups[i];

    groups.clear();

    int count = 0;

    QFile inputFile("buylist.txt");
    QStringList split;
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);

       for (int i = 0; !in.atEnd(); i++)
       {
          QString line = in.readLine();
          split = line.split(",");

          if(split[0] == username)
          {
              ui->verticalLayout_2->addWidget(createGroup(split[1]));
              count++;
          }
       }

       inputFile.close();
    }

    int sum = 0;

    for(int i = 0; i < spins.length(); i++)
    {
        sum += (spins.at(i)->value() * lineedits.at(i)->text().toInt());
    }

    ui->lineEdit->setText(QString::number(count));
    ui->lineEdit_2->setText(QString::number(sum));

    ui->lineEdit->setAlignment(Qt::AlignCenter);
    ui->lineEdit_2->setAlignment(Qt::AlignCenter);

    vSpacer = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);;                             // Not sure what to make of this
    ui->verticalLayout_2->addSpacerItem(vSpacer);
    spaces.push_back(vSpacer);
}


void buylist::on_pushButton_4_clicked()
{
    /****/
}

