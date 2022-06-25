#include "buy_list.h"
#include <QScrollArea>
#include <QCheckBox>

Buy_list::Buy_list(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Buy_list)
{
    setWindowTitle(tr("سبد خرید"));
    ui->setupUi(this);

////    QVBoxLayout* button_lay = new QVBoxLayout();
////    //button_lay->setSizeConstraint(QLayout::SetFixedSize);
////    setFixedSize(600,180);
////    //scrollArea = new QScrollArea();

////    button_lay->addWidget(createGroup());
////    button_lay->addWidget(createGroup());

//    QScrollArea *scrl = new QScrollArea();
//        scrl->setGeometry(0,0,300,300);
//        QWidget *wgtMain = new QWidget();
//        QHBoxLayout *hboxMain = new QHBoxLayout(wgtMain);
//        for(int iCount=0;iCount<3;iCount++){
//            QWidget *wgtSub = new QWidget();
//            QVBoxLayout *vboxSub = new QVBoxLayout(wgtSub);
//            for(int jCount=0;jCount<10;jCount++){
//                QCheckBox *chk = new QCheckBox("Check Box " + QString::number(jCount+1) + " of " + QString::number(iCount+1));
//                vboxSub->addWidget(chk);
//            }
//            hboxMain->addWidget(wgtSub);
//        }
//        scrl->setWidget(wgtMain);
//        scrl->show();

//    //setLayout(button_lay);

}

QGroupBox* Buy_list::createGroup()
{
    QGroupBox *groupBox = new QGroupBox("کالای 1");
    groups.push_back(groupBox);

    QHBoxLayout* main_layout = new QHBoxLayout();
    hlayout.push_back(main_layout);

    name = new QLabel("pruduct name");
    labels.push_back(name);

    price = new QLineEdit("142700");
    price->setReadOnly(true);
    lineedits.push_back(price);

    count = new QSpinBox;
    spins.push_back(count);

    remove = new QPushButton{"حذف"};
    //connect(buy,&QPushButton::clicked,[this, id] { on_buy_button(id); });
    buttons.push_back(remove);

    detail = new QPushButton{"جزئیات محصول"};
    //connect(detail,&QPushButton::clicked,[this, id] { on_detail_button(id); });
    buttons.push_back(detail);

    price->setMaximumWidth(60);
    price->setFixedWidth(60);
    price->setAlignment(Qt::AlignCenter);

    QVBoxLayout* button_lay = new QVBoxLayout;
    vlayout.push_back(button_lay);

    QLabel* space = new QLabel{"              "};
    labels.push_back(space);
    QLabel* pl = new QLabel{"قیمت نهایی"};
    labels.push_back(space);

    QLabel* countx = new QLabel{"count"};
    labels.push_back(countx);

    main_layout->addWidget(name);
    main_layout->addWidget(space);

    main_layout->addWidget(pl);

    main_layout->addWidget(price);

    main_layout->addWidget(space);

    main_layout->addWidget(countx);
    main_layout->addWidget(count);
    main_layout->addWidget(space);

    button_lay->addWidget(detail);
    button_lay->addWidget(remove);

    main_layout->addLayout(button_lay);
    main_layout->setSizeConstraint(QLayout::SetFixedSize);
    groupBox->setLayout(main_layout);

    return groupBox;
}

Buy_list::~Buy_list()
{
    delete lay;
//    delete next;
//    delete privious;
//    delete page_number;
//    delete numbers;
//    delete button_lay;

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
