#include "list_pruduct.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QFile>
#include "product_detail.h"
#include "report_page.h"
#include "buylist.h"

int list_pruduct::number = 0;

QGroupBox* list_pruduct::createGroup(int index)
{
    QFile inputFile("pruduct.txt");
    QStringList split;

    setFixedHeight(590);
    setMaximumHeight(590);

    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);

       for (int i = 0; i != index; i++)
       {
          QString line = in.readLine();
          split = line.split(",");
       }

       inputFile.close();
    }

    QGroupBox *groupBox = new QGroupBox(split[0]);
    groups.push_back(groupBox);

    QVBoxLayout* button_layout = new QVBoxLayout();
    vlayout.push_back(button_layout);

    QVBoxLayout* price_layout = new QVBoxLayout();
    vlayout.push_back(price_layout);

    QHBoxLayout* main_layout = new QHBoxLayout();
    hlayout.push_back(main_layout);

    QLabel* photo = new QLabel();
    QPixmap photo_source{".\\prudoct_picture\\" + QString::number(index) + ".png"};
    photo->setPixmap(photo_source.scaled(100,100));
    labels.push_back(photo);

    int fprice = split[1].toInt() * (100 - split[9].toInt());

    QLineEdit* price = new QLineEdit(split[1]);
    price->setDisabled(true);
    lineedits.push_back(price);

    QLineEdit* finally_price = new QLineEdit(QString::number(fprice / 100));
    finally_price->setReadOnly(true);
    lineedits.push_back(finally_price);

    QLabel* discount = new QLabel(split[9]+"%");
    labels.push_back(discount);

    if(split[9] == "0")
    {
        discount->setVisible(false);
        price->setVisible(false);
    }

    QString id = split[8];

    buy = new QPushButton{"افزودن به سبد خرید"};
    connect(buy,&QPushButton::clicked,[this, id] { on_buy_button(id); });
    buttons.push_back(buy);

    detail = new QPushButton{"جزئیات محصول"};
    connect(detail,&QPushButton::clicked,[this, id] { on_detail_button(id); });
    buttons.push_back(detail);

    report = new QPushButton{"گزارش تخلف"};
    connect(report,&QPushButton::clicked,[this, id] { on_report_button(id); });
    buttons.push_back(report);

    price->setMaximumWidth(60);
    price->setFixedWidth(60);
    price->setAlignment(Qt::AlignCenter);

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

QGroupBox *list_pruduct::createEmptyGroup()
{
    QGroupBox *groupBox = new QGroupBox{" "};
    groups.push_back(groupBox);

    setFixedWidth(920);
    setMaximumWidth(920);
    setFixedHeight(590);
    setMaximumHeight(590);

    return groupBox;
}

void list_pruduct::show_list(int index)
{
    int count = (index - 1) * 12;

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 3; j++)
        {
            if(count >= countlines("pruduct.txt"))
            {
                grid->addWidget(createEmptyGroup(), i, j);
                continue;
            }

            count ++;
            grid->addWidget(createGroup(count), i, j);
        }
}

list_pruduct::list_pruduct(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("لیست محصولات"));
    setFixedWidth(920);
    setMaximumWidth(920);
    setFixedHeight(585);
    setMaximumHeight(585);

    grid = new QGridLayout{this};
    show_list(1);

    button_lay = new QHBoxLayout();

    back = new QPushButton{"بازگشت"};
    connect(back,&QPushButton::clicked,[this] { on_back_button(); });

    next = new QPushButton{"صفحه بعد"};
    connect(next,&QPushButton::clicked,[this] { on_next_button(); });

    privious = new QPushButton{"صفحه قبل"};
    connect(privious,&QPushButton::clicked,[this] { on_privious_button(); });

    buy_list = new QPushButton{"سبد خرید"};
    connect(buy_list,&QPushButton::clicked,[this] { on_buy_list_button(); });

    page_number = new QLineEdit{"1"};
    page_number->setAlignment(Qt::AlignLeft);

    numbers = new QLabel{"from " + QString::number(((countlines("pruduct.txt") - 1) / 12) + 1)};
    page_number->setMaximumWidth(30);
    page_number->setFixedWidth(30);

    button_lay->addWidget(privious);
    button_lay->addWidget(page_number);
    button_lay->addWidget(numbers);
    button_lay->addWidget(next);
    button_lay->addWidget(buy_list);
    button_lay->addWidget(back);

    grid->addLayout(button_lay, 4, 1, 1, 2);

    setLayout(grid);
}

void list_pruduct::on_buy_button(QString id)
{
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
          {
              QMessageBox::warning(this,"اخطار","این کالا قبلا به سبد خرید اضافه شده است!");
              return;
          }
       }

       inputFile.close();
    }

    QFile file("buylist.txt");
    QTextStream stream( &file );

    file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);

    stream << username << "," << id << "\n";
    file.close();

    QMessageBox::information(this,"تایید","با موفقیت به سبد خرید اضافه شد!");
}

void list_pruduct::on_detail_button(QString id)
{
    Product_detail* temp = new Product_detail{this};
    connect(this, SIGNAL(sendPruductId(QString)), temp, SLOT(getId(QString)));
    temp->show();

    emit sendPruductId(id);
}

void list_pruduct::on_report_button(QString id)
{
    report_page* temp = new report_page{this};
    connect(this, SIGNAL(sendId(QString,QString)), temp, SLOT(getId(QString,QString)));
    temp->show();

    emit sendId(username,id);
}

void list_pruduct::on_back_button()
{
    close();
}

void list_pruduct::on_next_button()
{
    if((((countlines("pruduct.txt") - 1) / 12) + 1) == page_number->text().toInt())
    {
        QMessageBox::warning(this,"اخطار","صفحه بعد وجود ندارد");
        return;
    }

    for(int i = 0; i < groups.length(); i++)
        delete groups[i];

    groups.clear();

    page_number->setText(QString::number(page_number->text().toInt()+1));
    show_list(page_number->text().toInt());
}

void list_pruduct::on_privious_button()
{
    if(page_number->text().toInt() == 1)
    {
        QMessageBox::warning(this,"اخطار","صفحه قبل وجود ندارد");
        return;
    }

    for(int i = 0; i < groups.length(); i++)
        delete groups[i];

    groups.clear();

    page_number->setText(QString::number(page_number->text().toInt()-1));
    show_list(page_number->text().toInt());
}

void list_pruduct::getUserName(QString str)
{
    username = str;
}

void list_pruduct::on_buy_list_button()
{
    buylist* temp = new buylist{this};
    connect(this, SIGNAL(sendPruductId(QString)), temp, SLOT(getId(QString)));
    temp->show();
    close();
    emit sendPruductId(username);
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
    delete grid;
    delete back;
    delete next;
    delete privious;
    delete page_number;
    delete numbers;
    delete button_lay;

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

    for(int i = 0; i < groups.length(); i++)
        delete groups[i];

    groups.clear();
}
