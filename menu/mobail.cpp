#include "mobail.h"
#include "ui_mobail.h"
mobail::mobail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mobail)
{
    ui->setupUi(this);
}

mobail::~mobail()
{
    delete ui;
}
