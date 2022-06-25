#ifndef ADD_PRODUCT_H
#define ADD_PRODUCT_H

#include <QDialog>

namespace Ui {
class Add_Product;
}

class Add_Product : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Product(QWidget *parent = nullptr);
    ~Add_Product();
    static int countlines(QString filename);

private slots:
    void on_pushButton_clicked();
    void on_buttonBox_accepted();
    void getUserName(QString str);

private:
    Ui::Add_Product *ui;
    QPixmap imagePixmap;
};

#endif // ADD_PRODUCT_H
