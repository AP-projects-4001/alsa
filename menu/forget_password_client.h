#ifndef FORGET_PASSWORD_CLIENT_H
#define FORGET_PASSWORD_CLIENT_H

#include <QDialog>

namespace Ui {
class forget_password_client;
}

class forget_password_client : public QDialog
{
    Q_OBJECT

public:
    explicit forget_password_client(QWidget *parent = nullptr);
    ~forget_password_client();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::forget_password_client *ui;
private:
    void Write_to_file();
    void read_file();
     QVector<QString> nameVect;
     QVector<QString> password_vect;
     QVector<QString> address_vect;
     QVector<QString> phoneNumber;
     QVector<QString> card_numberVect;
     QVector<QString> CVV2_Vect;
     QVector<QString> money_Vect;
};

#endif // FORGET_PASSWORD_CLIENT_H
