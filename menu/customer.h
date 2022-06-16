#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>

namespace Ui {
class customer;
}

class customer : public QDialog
{
    Q_OBJECT

public:
    explicit customer(QWidget *parent = nullptr);
    ~customer();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    void read_file();
    Ui::customer *ui;
private:
    QVector<QString> Name__Vect;
    QVector<QString> BankCardNumber__vect;
    QVector<QString> CVV2_card__vect;
    QVector<QString> supply__vect;
};

#endif // CUSTOMER_H
