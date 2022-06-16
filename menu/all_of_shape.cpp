#include "all_of_shape.h"
#include "ui_all_of_shape.h"

All_of_shape::All_of_shape(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::All_of_shape)
{
    ui->setupUi(this);
}

All_of_shape::~All_of_shape()
{
    delete ui;
}
