#ifndef CUSTOMER_REGISTER_H
#define CUSTOMER_REGISTER_H
#include <qvector.h>
#include <QDialog>

namespace Ui {
class customer_register;
}

class customer_register : public QDialog
{
    Q_OBJECT

public:
    explicit customer_register(QWidget *parent = nullptr);
    ~customer_register();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::customer_register *ui;
private:
    void write_to_file();
    void read_file();
    QVector<QString> NameVect;
    QVector<QString> BankCardNumber_vect;
    QVector<QString> CVV2_card_vect;
    QVector<QString> supply_vect;
};

#endif // CUSTOMER_REGISTER_H
