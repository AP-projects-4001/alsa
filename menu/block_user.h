#ifndef BLOCK_USER_H
#define BLOCK_USER_H

#include <QDialog>

namespace Ui {
class block_user;
}

class block_user : public QDialog
{
    Q_OBJECT

public:
    explicit block_user(QWidget *parent = nullptr);
    ~block_user();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::block_user *ui;
    void read_file();
    void Write_to_file();
    QVector<QString> nameVect;
    QVector<QString> password_vect;
    QVector<QString> card_numberVect;
    QVector<QString> CVV2_Vect;
    QVector<QString> money_Vect;
    QVector<QString> block;
};

#endif // BLOCK_USER_H
