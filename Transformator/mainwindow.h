#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "transformator.h"
#include <QMainWindow>
#include <QtPrintSupport/QPrinter>
#include <QFileSystemModel>
#include <QtGui>
#include <QDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void makePlot(void);
    void on_TV_fileSystem_clicked(const QModelIndex &index);
    void on_LV_showFiles_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;
    QFileSystemModel *dataFileModel;
    QStringList nameFilter;
    QString sPath;
    QString filePath;
    QVector<double> data_x, data_y, data_z;
    void setNameFilter();
    void setRoot(QString Path);
    void setDirModel();
    void setFileModel();
    void setDataFileModel();
    void GenerateData(int sizeVec);
    void setGraphNew();
    void setGraphOrigin();
    void loadDataFromFile();
    void convertDataFromFile(QString Path);
};

#endif // MAINWINDOW_H
