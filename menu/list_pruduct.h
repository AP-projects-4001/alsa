#ifndef LIST_PRUDUCT_H
#define LIST_PRUDUCT_H

#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLineEdit>

class list_pruduct : public QDialog
{
    Q_OBJECT

public:
    list_pruduct(QWidget *parent = nullptr);
    ~list_pruduct();
    int countlines(QString fname);

signals:
    void sendString(QString);

private slots:
    void on_buy_button(QString id);
    void on_detail_button(QString id);
    void on_report_button(QString id);

private:
    QGroupBox *createGroup();

    QVector<QPushButton*> buttons;
    QVector<QLabel*> labels;
    QVector<QLineEdit*> lineedits;
    QVector<QGridLayout*> hlayout;
    QVector<QVBoxLayout*> vlayout;
    QVector<QHBoxLayout*> glayout;

    static int number;
    QPushButton* buy;
    QPushButton* detail;
    QPushButton* report;
};

#endif // LIST_PRUDUCT_H
