#include "product.h"
#include <QFile>
#include <QTextStream>

product::product()
{

}

int product::countlines(QString fname)
{
    QFile file(fname);
    int line_count = 0;

    QString line[10000];
    QTextStream in(&file);

    file.open(QIODevice::ReadWrite);

    while( !in.atEnd())
    {
        line[line_count]=in.readLine();
        line_count++;
    }

    file.close();
    return line_count;
}
