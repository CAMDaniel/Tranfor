#ifndef ASCLOADER_H
#define ASCLOADER_H

#include <QMap>
#include <string>
#include <QString>
#include <iostream>
#include <sys/stat.h>
#include <QVector>

struct TMETADATA {
    size_t           mID;
    size_t           mTotalPoint;
    std::string      mAxisTitle_x;
    std::string      mAxisTitle_y;
    double           mSamplingRate;
    double           mAxisMultiplier_x;
    double           mAxisMultiplier_y;
    double          *mData_x;
    double          *mData_y;
};

class ASCLoader
{
public:
    ASCLoader();
    ~ASCLoader();

public:
    void setPath(QString path);

public:
    QVector<double>               getVector_x()       {   return mVector_x;    }
    QVector<double>               getVector_y()       {   return mVector_y;    }
    QMap<QString, QString>        getHeaderData()     {   return mHeaderData;  }

private:
    void loadDataFromFile(const char *fileName);
    void loadHeaderData(const char *fileName);
    bool fileExist(const char *fileName);
    size_t getFileSize(const char *fileName);

private:
    TMETADATA                    *mMetaData;
    QMap<QString, QString>        mHeaderData;
    size_t                        mMaxChannels;
    QVector<double>               mVector_x;
    QVector<double>               mVector_y;
};

#endif // ASCLOADER_H
