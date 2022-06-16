#ifndef ALL_OF_SHAPE_H
#define ALL_OF_SHAPE_H

#include <QDialog>

namespace Ui {
class All_of_shape;
}

class All_of_shape : public QDialog
{
    Q_OBJECT

public:
    explicit All_of_shape(QWidget *parent = nullptr);
    ~All_of_shape();

private:
    Ui::All_of_shape *ui;
private:
      QVector <QString>  name;
      QVector <QString>  color;
      QVector <QString> price;
};

#endif // ALL_OF_SHAPE_H
