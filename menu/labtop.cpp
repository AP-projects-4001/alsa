#include "labtop.h"
#include "ui_labtop.h"

labtop::labtop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::labtop)
{
    ui->setupUi(this);
}

labtop::~labtop()
{
    delete ui;
}
