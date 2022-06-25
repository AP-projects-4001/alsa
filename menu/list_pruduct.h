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
    void sendId(QString,QString);
    void sendPruductId(QString);

private slots:
    void on_buy_button(QString id);
    void on_detail_button(QString id);
    void on_report_button(QString id);
    void on_back_button();
    void on_next_button();
    void on_privious_button();
    void getUserName(QString str);
    void on_buy_list_button();

private:
    QString username;

    QGroupBox* createGroup(int index);
    QGroupBox* createEmptyGroup();

    QVector<QPushButton*> buttons;
    QVector<QLabel*> labels;
    QVector<QLineEdit*> lineedits;
    QVector<QVBoxLayout*> vlayout;
    QVector<QHBoxLayout*> hlayout;
    QVector<QGroupBox*> groups;

    QGridLayout *grid;

    static int number;
    void show_list(int i);
    QPushButton* buy;
    QPushButton* detail;
    QPushButton* report;
    QPushButton* back;
    QPushButton* next;
    QPushButton* buy_list;
    QPushButton* privious;
    QLineEdit* page_number;
    QLabel* numbers;
    QHBoxLayout* button_lay;
};

#endif // LIST_PRUDUCT_H
