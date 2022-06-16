#ifndef FORGETPASSWORD_H
#define FORGETPASSWORD_H

#include <QDialog>

namespace Ui {
class forgetpassword;
}

class forgetpassword : public QDialog
{
    Q_OBJECT

public:
    explicit forgetpassword(QWidget *parent = nullptr);
    ~forgetpassword();

private slots:
    void on_buttonBox_accepted();

    void ADD_item(QString name);

private:
    void read_file();
    void Write_to_file();
private:
    Ui::forgetpassword *ui;
private:
    QVector <QString> Name_vect;
    QVector <QString> Phonenumber_vect;
    QVector <QString> Address_vect;
    QVector <QString> Password_vect;
    QVector <QString> Card_Bank_vect;
    QVector <QString> CVV2_of_card;
    QVector<QString> Supply_Vect;
};

#endif // FORGETPASSWORD_H
