#ifndef INCREASE_MONEY_H
#define INCREASE_MONEY_H

#include <QDialog>

namespace Ui {
class increase_money;
}

class increase_money : public QDialog
{
    Q_OBJECT

public:
    explicit increase_money(QWidget *parent = nullptr);
    ~increase_money();

private slots:

    void add_money(QString);

    void on_buttonBox_accepted();

    void add_item(QString,QString);
private:
    Ui::increase_money *ui;
private:
    void Write_to_file();
    void Write_to_file_cus();
    void Read_file_cus();
    void Write_to_file_remove();
    void read_file();
    void Read_file();
    void Write_to_file_history();
    void Read_file_history();
    void increas_money_of_customer();
    QString username;
    QVector <QString> Name_vect_cus;
    QVector <QString> Password_vect_cus;
    QVector <QString> Card_Bank_vect_cus;
    QVector <QString> CVV2_of_card_cus;
    QVector <QString> Supply_Vect_cus;
    QVector <QString> Block;
    QVector <QString> Name_vect;
    QVector <QString> Phonenumber_vect;
    QVector <QString> Address_vect;
    QVector <QString> Password_vect;
    QVector <QString> Card_Bank_vect;
    QVector <QString> CVV2_of_card;
    QVector <QString> Supply_Vect;
    QVector<QString> customer_name;
    QVector<QString> client_name;
    QVector<QString> price;
    QVector<QString> counter;
    QVector<QString> customer_name_his;
    QVector<QString> client_name_his;
    QVector<QString> price_his;
    QVector<QString> counter_his;
    QVector<QString> customer_name_remove;
    QVector<QString> client_name_remove;
    QVector<QString> price_remove;
    QVector<QString> counter_remove;
    bool check_buy = false;
};

#endif // INCREASE_MONEY_H
