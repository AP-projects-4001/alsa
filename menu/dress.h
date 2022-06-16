#ifndef DRESS_H
#define DRESS_H

#include <QDialog>

namespace Ui {
class Dress;
}

class Dress : public QDialog
{
    Q_OBJECT

public:
    explicit Dress(QWidget *parent = nullptr);
    ~Dress();

private:
    Ui::Dress *ui;
private:
   QVector<QString> material;
   QVector <QString>  name;
   QVector <QString>  color;
   QVector <QString> price;
};

#endif // DRESS_H
