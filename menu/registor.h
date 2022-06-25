#ifndef REGISTOR_H
#define REGISTOR_H

#include <QDialog>

namespace Ui {
class Registor;
}

class Registor : public QDialog
{
    Q_OBJECT

public:
    explicit Registor(QWidget *parent = nullptr);
    ~Registor();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Registor *ui;
    void Write_to_file();
    void read_file();
private:
     QVector<QString> nameVect;
     QVector<QString> password_vect;
     QVector<QString> card_numberVect;
     QVector<QString> CVV2_Vect;
     QVector<QString> money_Vect;
};

#endif // REGISTOR_H
