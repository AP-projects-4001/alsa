#ifndef REGISTER_H
#define REGISTER_H
#include <qvector.h>
#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Register *ui;
private:
   QVector <QString> name_vect;
   QVector <QString> phonenumber_vect;
   QVector <QString> address_vect;
   QVector <QString> password_vect;
   QVector <QString> CardBank_vect;
   QVector <QString> CVV2_ofCard_vect;
   QVector <QString> Supply_Vect;
private:
   void Write_to_file();
   void Read_from_file();
};

#endif // REGISTER_H
