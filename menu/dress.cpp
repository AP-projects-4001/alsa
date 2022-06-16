#include "dress.h"
#include "ui_dress.h"
#include "all_of_shape.h"
Dress::Dress(QWidget *parent) :QDialog(parent),
    ui(new Ui::Dress)
{
    ui->setupUi(this);
}

Dress::~Dress()
{

    delete ui;
}
