#ifndef BUYLIST_H
#define BUYLIST_H

#include <QDialog>
#include <QGroupBox>
#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QSpinBox>

namespace Ui {
class buylist;
}

class buylist : public QDialog
{
    Q_OBJECT

public:
    explicit buylist(QWidget *parent = nullptr);
    ~buylist();

private slots:
    void on_pushButton_clicked();
    void getId(QString str);
    void spin_count_changed(int value);
    void on_remove_button_clicked(QString id);
    void on_pushButton_2_clicked();
    void show_list();

    void on_pushButton_4_clicked();

private:
    Ui::buylist *ui;
    QGroupBox* createGroup(QString pruduct_id);
    QString username;
    QVector<QPushButton*> buttons;
    QVector<QLabel*> labels;
    QVector<QLineEdit*> lineedits;
    QVector<QVBoxLayout*> vlayout;
    QVector<QHBoxLayout*> hlayout;
    QVector<QGroupBox*> groups;
    QVector<QSpinBox*> spins;
    QVector<QSpacerItem*> spaces;

    QSpacerItem* vSpacer;

    QSpacerItem* verticalSpacer;
    QPushButton* remove;
    QPushButton* detail;
    QLabel* name;
    QLineEdit* price;
    QSpinBox* count;
    QHBoxLayout* lay;
};

#endif // BUYLIST_H
