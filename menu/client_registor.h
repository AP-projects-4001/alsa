#ifndef CLIENT_REGISTOR_H
#define CLIENT_REGISTOR_H
#include <QDialog>
#include"persongclientt.h"
namespace Ui {
class client_registor;
}

class client_registor : public QDialog,public personGclientt
{
    Q_OBJECT

public:
    explicit client_registor(QWidget *parent = nullptr);
    ~client_registor();
private slots:
    void on_buttonBox_accepted();
private:
    Ui::client_registor *ui;
};

#endif // CLIENT_REGISTOR_H
