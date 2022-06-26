#ifndef REGISTOR_H
#define REGISTOR_H
#include"persong.h"
#include <QDialog>

namespace Ui {
class Registor;
}

class Registor : public QDialog,public personG
{
    Q_OBJECT

public:
    explicit Registor(QWidget *parent = nullptr);
    ~Registor();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Registor *ui;
};

#endif // REGISTOR_H
