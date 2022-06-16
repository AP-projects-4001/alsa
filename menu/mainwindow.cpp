#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "client.h"
#include "admin.h"
#include "customer.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    exit(0);
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()){
       client* d = new client(this);
       d->show();
    }
    else if(ui->radioButton_2->isChecked()){
       admin* d = new admin(this);
       d->show();
    }
    else{
        customer* d = new customer(this);
        d->show();
    }

}

