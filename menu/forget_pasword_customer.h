#ifndef FORGET_PASWORD_CUSTOMER_H
#define FORGET_PASWORD_CUSTOMER_H
#include"persong.h"
#include <QDialog>

namespace Ui {
class forget_pasword_customer;
}

class forget_pasword_customer : public QDialog,public personG
{
    Q_OBJECT

public:
    explicit forget_pasword_customer(QWidget *parent = nullptr);
    ~forget_pasword_customer();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::forget_pasword_customer *ui;

};

#endif // FORGET_PASWORD_CUSTOMER_H
