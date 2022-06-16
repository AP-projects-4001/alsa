#ifndef LABTOP_H
#define LABTOP_H

#include <QDialog>

namespace Ui {
class labtop;
}

class labtop : public QDialog
{
    Q_OBJECT

public:
    explicit labtop(QWidget *parent = nullptr);
    ~labtop();

private:
    Ui::labtop *ui;
    QVector <QString>  name;
    QVector <QString>  color;
    QVector <QString> price;
    QVector <QString> year;
    QVector <QString> ram;
    QVector <QString> madein;

};

#endif // LABTOP_H
