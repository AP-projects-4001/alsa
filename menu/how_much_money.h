#ifndef HOW_MUCH_MONEY_H
#define HOW_MUCH_MONEY_H

#include <QDialog>

namespace Ui {
class how_much_money;
}

class how_much_money : public QDialog
{
    Q_OBJECT

public:
    explicit how_much_money(QWidget *parent = nullptr);
    ~how_much_money();

private slots:
    void on_buttonBox_accepted();
signals:
    void add_money(QString);
private:
    Ui::how_much_money *ui;
};

#endif // HOW_MUCH_MONEY_H
