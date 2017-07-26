#ifndef TRANSFORMATOR_H
#define TRANSFORMATOR_H

#include <iostream>
#include <QString>
#include <QVector>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QMainWindow>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>
#include "echmetqtengine.h"

class Transformator
{
public:
    Transformator();
    Transformator(QString path);
    Transformator(double * data_x, double * data_y, size_t size);
    Transformator(double * data_x, size_t size, QString func);
    Transformator(QVector<double> data_x, QVector<double> data_y);
    Transformator(QVector<double> data_x, QString func);
    ~Transformator();
    void setPath(QString path);
    void saveFileAs(QString pathNewFile);
    void transform(QString func);
    QVector<double> vector_x(void);
    QVector<double> vector_y(void);
    double * data_x(void)           {   return mData_x;     }
    double * data_y(void)           {   return mData_y;     }
    size_t size(void)               {   return mSize;       }
    QString path(void)              {   return mPath;       }
    QString newPath(void)           {   return mNewPath;    }

private:
    void loadData(void);
    void initData();
    double countDataY(QString func, double x);

private:
    double  *           mData_x;
    double  *           mData_y;
    QVector<double>     mVector_x;
    QVector<double>     mVector_y;
    size_t              mSize;
    QString             mPath;
    QString             mNewPath;
    EchmetQtEngine      mEngine;
};

#endif // TRANSFORMATOR_H
