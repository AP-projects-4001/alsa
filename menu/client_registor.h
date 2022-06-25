#ifndef CLIENT_REGISTOR_H
#define CLIENT_REGISTOR_H

#include <QDialog>

namespace Ui {
class client_registor;
}

class client_registor : public QDialog
{
    Q_OBJECT

public:
    explicit client_registor(QWidget *parent = nullptr);
    ~client_registor();
private slots:
    void on_buttonBox_accepted();

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
private:
    Ui::client_registor *ui;
};

#endif // CLIENT_REGISTOR_H
