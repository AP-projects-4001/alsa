#ifndef FORGET_PASWORD_CUSTOMER_H
#define FORGET_PASWORD_CUSTOMER_H

#include <QDialog>

namespace Ui {
class forget_pasword_customer;
}

class forget_pasword_customer : public QDialog
{
    Q_OBJECT

public:
    explicit forget_pasword_customer(QWidget *parent = nullptr);
    ~forget_pasword_customer();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::forget_pasword_customer *ui;
private:
     QVector<QString> nameVect;
     QVector<QString> password_vect;
     QVector<QString> card_numberVect;
     QVector<QString> CVV2_Vect;
     QVector<QString> money_Vect;
     void Write_to_file();
     void read_file();

};

#endif // FORGET_PASWORD_CUSTOMER_H
