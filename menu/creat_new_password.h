#ifndef CREAT_NEW_PASSWORD_H
#define CREAT_NEW_PASSWORD_H
#include <qvector.h>
#include <QDialog>
namespace Ui {
class creat_new_password;
}

class creat_new_password : public QDialog
{
    Q_OBJECT

public:
    explicit creat_new_password(QWidget *parent = nullptr);
    ~creat_new_password();

private slots:
    void on_buttonBox_accepted();
private:
   void Read_file();

private:
    Ui::creat_new_password *ui;
};

#endif // CREAT_NEW_PASSWORD_H
