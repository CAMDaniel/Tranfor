#include "ascloader.h"

#define ROWLEN              (65536*2)

ASCLoader::ASCLoader()
    :mMetaData(NULL)
{

}

ASCLoader::~ASCLoader()
{
    if(mMetaData) {
        for (size_t i=0; i<mMaxChannels; ++i) {
            delete [] mMetaData->mData_x;
            delete [] mMetaData->mData_y;
        }
        delete [] mMetaData;
    }
}

void ASCLoader::setPath(QString path)
{
    loadHeaderData(path.toUtf8().constData());
    loadDataFromFile(path.toUtf8().constData());
}

void ASCLoader::loadDataFromFile(const char *fileName)
{

}

void ASCLoader::loadHeaderData(const char *fileName)
{
    FILE *file=fopen(fileName, "r");
    char row[ROWLEN], *neof=row;
    char nameData[ROWLEN];
    char letter='0';

    //version
    int version, count;
    neof=fgets(row, ROWLEN, file);
    if(sscanf(neof, "Version:%c%d", &letter, &version)!=2) throw "Data error.";
    mHeaderData.insert("Version", QString::number(version));

    //Maxchannels
    neof=fgets(row, ROWLEN, file);
    if(sscanf(neof, "Maxchannels:%c%d", &letter, &count)!=2) throw "Data error.";
    mMaxChannels=count;
    mMetaData=new TMETADATA [mMaxChannels];
    mHeaderData.insert("Maxchannels", QString::number(count));

    //Sample ID
    neof=fgets(row, ROWLEN, file);
    if(sscanf(neof, "Sample ID:%c%[^\n]", &letter, &nameData)!=2) throw "Data error.";
    mHeaderData.insert("Sample ID", QString::fromStdString(std::string(nameData)));

    //Data File
    neof=fgets(row, ROWLEN, file);
    if(sscanf(neof, "Data File:%c%[^\n]", &letter, &nameData)!=2) throw "Data error.";
    mHeaderData.insert("Data File", QString::fromStdString(std::string(nameData)));

    //Method
    neof=fgets(row, ROWLEN, file);
    if(sscanf(neof, "Method:%c%[^\n]", &letter, &nameData)!=2) throw "Data error.";
    mHeaderData.insert("Method", QString::fromStdString(std::string(nameData)));

    //User Name
    neof=fgets(row, ROWLEN, file);
    if(sscanf(neof, "User Name:%c%[^\n]", &letter, &nameData)!=2) throw "Data error.";
    mHeaderData.insert("User Name", QString::fromStdString(std::string(nameData)));

    //Acquisition Date and Time:
    neof=fgets(row, ROWLEN, file);
    if(sscanf(neof, "Acquisition Date and Time:%c%[^\n]", &letter, &nameData)!=2) throw "Data error.";
    mHeaderData.insert("Acquisition Date and Time", QString::fromStdString(std::string(nameData)));


    //Sampling Rate:
    double sampRate=0;
    neof=fgets(row, ROWLEN, file);
    if(sscanf(neof, "Sampling Rate:%c%[^\n]", &letter, &nameData)!=2) throw "Data error.";
    for (size_t i=0; i<mMaxChannels; ++i) {
        sscanf(nameData, "%lf%c", &sampRate, &letter);
        mMetaData[i].mID=i;
        mMetaData[i].mSamplingRate=sampRate;
    }

    int totalPoint=0;
    neof=fgets(row, ROWLEN, file);
    if(sscanf(neof, "Total Data Points:%c%[^P]Pts", &letter, &nameData)!=2) throw "Data error.";
    for (size_t i=0; i<mMaxChannels; ++i) {
        sscanf(nameData, "%d%c", &totalPoint, &letter);
        mMetaData[i].mTotalPoint=totalPoint;
        mMetaData[i].mData_x=new double [totalPoint];
        mMetaData[i].mData_y=new double [totalPoint];
    }

    char axis[100];
    neof=fgets(row, ROWLEN, file);
    if(sscanf(neof, "X Axis Title:%c%[^\n]", &letter, &nameData)!=2) throw "Data error.";
    for (size_t i=0; i<mMaxChannels; ++i) {
        if(i==mMaxChannels-1) {
            sscanf(nameData, "%s", axis);
        }

        if(letter=='\n' || letter=='\t') {
            sscanf(nameData, "%[^\t\n]",    axis);
        } else if (letter==',') {
            sscanf(nameData, "%[^,]",       axis);
        } else if (letter==';') {
            sscanf(nameData, "%[^;];",      axis);
        }
        std::string tmp=std::string(axis);
        mMetaData[i].mAxisTitle_x=tmp;
    }

    neof=fgets(row, ROWLEN, file);
    if(sscanf(neof, "Y Axis Title:%c%[^\n]", &letter, &nameData)!=2) throw "Data error.";
    for (size_t i=0; i<mMaxChannels; ++i) {

        if(i==mMaxChannels-1) {
            sscanf(nameData, "%s", axis);
        }

        if(letter=='\n' || letter=='\t') {
            sscanf(nameData, "%[^\t\n]",  axis);
        } else if (letter==',') {
            sscanf(nameData, "%[^,]", axis);
        } else if (letter==';') {
            sscanf(nameData, "%[^;];", axis);
        }
        std::string tmp=std::string(axis);
        mMetaData[i].mAxisTitle_y=tmp;
    }

    double multi=0;
    neof=fgets(row, ROWLEN, file);
    if(sscanf(neof, "X Axis Multiplier:%c%[^\n]", &letter, &nameData)!=2) throw "Data error.";
    for (size_t i=0; i<mMaxChannels; ++i) {
        sscanf(nameData, "%lf%c", &multi, &letter);
        mMetaData[i].mAxisMultiplier_x=multi;
    }

    neof=fgets(row, ROWLEN, file);
    if(sscanf(neof, "Y Axis Multiplier:%c%[^\n]", &letter, &nameData)!=2) throw "Data error.";
    for (size_t i=0; i<mMaxChannels; ++i) {
        sscanf(nameData, "%lf%c", &multi, &letter);
        mMetaData[i].mAxisMultiplier_y=multi;
    }


    for (size_t i=0; i<mMaxChannels; ++i) {
        double val=0;
        for (size_t j=0; j<mMetaData[i].mTotalPoint; ++j) {
            neof=fgets(row, ROWLEN, file);
            sscanf(neof, "%lf", &val);
            mMetaData[i].mData_y[j]=val*mMetaData[i].mAxisMultiplier_y;
            mMetaData[i].mData_x[j]=(1/mMetaData[i].mSamplingRate)*j*mMetaData[i].mAxisMultiplier_x;
        }
    }
    std::fclose(file);
}

bool ASCLoader::fileExist(const char *fileName)
{
    struct stat buffer;
    return (stat(fileName, &buffer)==0);
}

size_t ASCLoader::getFileSize(const char *fileName)
{
    FILE *file=fopen(fileName, "r");
    std::fseek(file, 0, SEEK_END);
    size_t fileSize=std::ftell(file);
    std::fclose(file);
    return fileSize;
}
