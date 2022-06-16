#ifndef MENO_OF_BUY_H
#define MENO_OF_BUY_H

#include <QDialog>

namespace Ui {
class meno_of_buy;
}

class meno_of_buy : public QDialog
{
    Q_OBJECT

public:
    explicit meno_of_buy(QWidget *parent = nullptr);
    ~meno_of_buy();

private:
    Ui::meno_of_buy *ui;
};

#endif // MENO_OF_BUY_H
