#ifndef BUY_LIST_H
#define BUY_LIST_H

#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QScrollArea>

namespace Ui {
class Buy_list;
}

class Buy_list : public QDialog
{
    Q_OBJECT

public:
    explicit Buy_list(QWidget *parent = nullptr);
    ~Buy_list();

private:
    QGroupBox* createGroup();
    QScrollArea *scrollArea;
    QVector<QPushButton*> buttons;
    QVector<QLabel*> labels;
    QVector<QLineEdit*> lineedits;
    QVector<QVBoxLayout*> vlayout;
    QVector<QHBoxLayout*> hlayout;
    QVector<QGroupBox*> groups;
    QVector<QSpinBox*> spins;
    QVector<QSpacerItem*> spaces;

    QPushButton* remove;
    QPushButton* detail;
    QLabel* name;
    QLineEdit* price;
    QSpinBox* count;
    QHBoxLayout* lay;

    Ui::Buy_list *ui;
};

#endif // BUY_LIST_H
