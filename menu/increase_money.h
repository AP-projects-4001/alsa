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
    void on_pushButton_clicked();

    void add_money(QString);

    void on_buttonBox_accepted();

private:
    Ui::increase_money *ui;
private:
    void Write_to_file();
    void read_file();
    QVector <QString> Name_vect;
    QVector <QString> Phonenumber_vect;
    QVector <QString> Address_vect;
    QVector <QString> Password_vect;
    QVector <QString> Card_Bank_vect;
    QVector <QString> CVV2_of_card;
    QVector <QString> Supply_Vect;
};

#endif // INCREASE_MONEY_H
