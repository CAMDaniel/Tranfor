#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ascloader.h"
#include <QMainWindow>
#include <QtPrintSupport/QPrinter>
#include <QFileSystemModel>
#include <QtGui>
#include <QDialog>
#include "transformator.h"

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
    void on_TV_fileSystem_clicked(const QModelIndex &index);
    void on_LV_showFiles_clicked(const QModelIndex &index);
    void on_BT_changeData_clicked();

    void on_BT_changeData_2_clicked();

private:
    void openFile(QString path);
    void setNameFilter();
    void setRoot(QString Path);
    void setDirModel();
    void setFileModel();
    void setDataFileModel();
    void saveFileAs(QString path);
    void drawGraphOrigin(QVector<double> data_x, QVector<double> data_y);
    void drawGraphNew(QVector<double> data_x, QVector<double> data_y);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;
    QFileSystemModel *dataFileModel;
    QString mFilePath;
    QStringList nameFilter;
    QString sPath;
    QString filePath;
    QString func;
    ASCLoader mLoader;
    Transformator mData;
};

#endif // MAINWINDOW_H
