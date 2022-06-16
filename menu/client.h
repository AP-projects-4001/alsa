#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_buttonBox_accepted();

private:
    Ui::client *ui;
private:
    void Read_from_file();
    QVector <QString> NAME_VECT;
    QVector <QString> PHonenumber_Vect;
    QVector <QString> ADDress_Vect;
    QVector <QString> PASSWord_Vect;
    QVector <QString> Card_Bank_vect;
    QVector <QString> CVV2_of_card;
    QVector<QString> Supply_Vect;
};

#endif // CLIENT_H
