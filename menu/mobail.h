#ifndef MOBAIL_H
#define MOBAIL_H
#include "all_of_shape.h"
#include <QDialog>

namespace Ui {
class mobail;
}

class mobail : public QDialog
{
    Q_OBJECT

public:
    explicit mobail(QWidget *parent = nullptr);
    ~mobail();

private:
    QVector  <QString> year;
    QVector  <QString> colore;
    QVector  <QString> name;
    QVector  <QString> madein;
    Ui::mobail *ui;
};

#endif // MOBAIL_H
