#include "transformator.h"

Transformator::Transformator()
{
}

Transformator::Transformator(QString path)
{
    this->mPath=path;
    loadData();
}

Transformator::Transformator(double *data_x, double * data_y, size_t size)
{
    this->mSize=size;
    initData();
    for (size_t i=0; i<mSize; ++i) {
        mData_x[i]=data_x[i];
        mData_y[i]=data_y[i];
    }
}


double Transformator::countDataY(QString func, double x)
{
//    QScriptEngine eng;
//    eng.globalObject().setProperty("x", x);
//    eng.globalObject().setProperty("sin(x)", sin(x));

//    QScriptValue Cos=eng.newFunction(QCos);
//    eng.globalObject().setProperty("cos", Cos);

//    QScriptValue val=eng.evaluate(func);
//    return al.toNumber();
    mEngine.setVar(x);
    mEngine.setFunc(func);
    return mEngine.getRes();
}

Transformator::Transformator(double *data_x, size_t size, QString func)
{
    this->mSize=size;
    initData();
    for (size_t i=0; i<mSize; ++i) {
        mData_x[i]=data_x[i];
        mData_y[i]=countDataY(func, data_x[i]);
    }
}

Transformator::Transformator(QVector<double> data_x, QVector<double> data_y)
{
   this->mSize=data_x.size();
   initData();
   for (int i=0; i<data_x.size(); ++i) {
        mData_x[i]=data_x[i];
        mData_y[i]=data_y[i];
   }
}

Transformator::Transformator(QVector<double> data_x, QString func)
{
    this->mSize=data_x.size();
    for (size_t i=0; i<mSize; ++i) {
        mData_x[i]=data_x[i];
        mData_y[i]=countDataY(func, data_x[i]);
    }
}

Transformator::~Transformator()
{
    delete [] mData_x;
    delete [] mData_y;
    mData_x=NULL;
    mData_y=NULL;
}

void Transformator::setPath(QString path)
{
    this->mPath=path;
    loadData();
}

void Transformator::saveFileAs(QString pathNewFile)
{
    QFile file(pathNewFile);
    if(file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        for(size_t i=0; i<mSize; ++i)
            out<<QString::number(mData_x[i])<<";"<<QString::number(mData_y[i])<<"\n";
        file.close();
    }
}

void Transformator::transform(QString func)
{
    for (size_t i=0; i<mSize; ++i)
        mData_y[i]=countDataY(func, mData_x[i]);
}

QVector<double> Transformator::vector_x()
{
   mVector_x.resize(mSize);
   for (size_t i=0; i<mSize; ++i)
       mVector_x[i]=mData_x[i];
   return mVector_x;
}

QVector<double> Transformator::vector_y()
{
   mVector_y.resize(mSize);
   for (size_t i=0; i<mSize; ++i)
       mVector_y[i]=mData_y[i];
   return mVector_y;
}

void Transformator::initData(void)
{
    mData_x=new double [mSize];
    mData_y=new double [mSize];
}

//void Transformator::loadData()
//{
//    QFile file(mPath);
//    if(!file.open(QIODevice::ReadOnly)) {
//        QMessageBox::information(0, "error", file.errorString());
//    }

//    QTextStream in(&file);
//    QStringList list;
//    QStringList model;
//    while(!in.atEnd()) {
//        QString line = in.readLine();
//        list = line.split(";");
//        for (int i=0; i<list.size(); ++i)
//            model.append(list[i]);
//    }

//    mSize=model.size()/2;
//    initData();

//    for(int i=0; i<model.size(); i+=2) {
//        mData_x[i/2]=model[i].toDouble();
//        mData_y[i/2]=model[i+1].toDouble();
//    }
//    file.close();
//}


void Transformator::loadData()
{
    QFile file(mPath);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    QStringList list;

    std::vector<std::string> data_x;
    std::vector<std::string> data_y;
    while(!in.atEnd()) {
        QString line = in.readLine();
        list = line.split(";");
        for (int i=0; i<list.size(); ++i) {
            line=list[i];
            data_x.push_back(line.toStdString());
            line=list[++i];
            data_y.push_back(line.toStdString());
        }
    }

    if(data_x.size()!=data_y.size())
        QMessageBox::information(0, "The file has not correct data, "
                                    "number of x data is not equal y data.", file.errorString());
    mSize=data_x.size();
    initData();
    size_t idx=-1;
    for (auto const &it:data_x)
        mData_x[++idx]=stringToDouble(it);
    idx=-1;
    for (auto const &it:data_y)
        mData_y[++idx]=stringToDouble(it);

    file.close();
}

double Transformator::stringToDouble(std::string str)
{
    return ::atof(str.c_str());
}
