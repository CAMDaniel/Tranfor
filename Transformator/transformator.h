#ifndef TRANSFORMATOR_H
#define TRANSFORMATOR_H

#include <iostream>
#include <QString>
#include <QVector>

class Transformator
{
public:
    Transformator(QVector<double> *data_x, QVector<double> *data_y, QString *function);
    ~Transformator();

protected:
private:
};

#endif // TRANSFORMATOR_H
