#include "mainwindow.h"
#include "ui_mainwindow.h"

#define SET_ROOT_PATH   "/"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setRoot(SET_ROOT_PATH);
    setNameFilter();
    setDirModel();
    setFileModel();
    setDataFileModel();
    //GenerateData(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setDirModel(void)
{
    dirModel=new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel->setRootPath(sPath);
    ui->TV_fileSystem->setModel(dirModel);
}

void MainWindow::setFileModel(void)
{
    fileModel=new QFileSystemModel(this);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    fileModel->setRootPath(sPath);
    fileModel->setNameFilters(nameFilter);
    fileModel->setNameFilterDisables(false);
    ui->LV_showFiles->setModel(fileModel);
}

void MainWindow::setDataFileModel(void)
{
    dataFileModel=new QFileSystemModel(this);
    dataFileModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    dataFileModel->setRootPath(sPath);
    dataFileModel->setNameFilters(nameFilter);
    dataFileModel->setNameFilterDisables(false);
    ui->TV_dataFiles->setModel(dataFileModel);
}

void MainWindow::setNameFilter(void)
{
    this->nameFilter<<"*.txt";
}

void MainWindow::setRoot(QString Path)
{
    this->sPath=Path;
}

void MainWindow::on_TV_fileSystem_clicked(const QModelIndex &index)
{
   QString sPath=dirModel->fileInfo(index).absoluteFilePath();
   ui->LV_showFiles->setRootIndex(fileModel->setRootPath(sPath));
   ui->TV_dataFiles->setRootIndex(dataFileModel->setRootPath(sPath));
}

void MainWindow::openFile(QString path)
{
   QFile file(path);
   this->filePath=path;
   if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info", file.errorString());
   QTextStream in(&file);
   ui->TE_OriginFile->setText(path);
   ui->TB_OriginData->setText(in.readAll());
   file.close();
}

void MainWindow::on_LV_showFiles_clicked(const QModelIndex &index)
{
   ui->TB_NewData->clear();
   QString path=dirModel->fileInfo(index).absoluteFilePath();
   openFile(path);

   mData.setPath(path);
   drawGraphOrigin(mData.vector_x(), mData.vector_y());
   drawGraphNew(mData.vector_x(), mData.vector_y());
}

void MainWindow::saveFileAs(QString path)
{
    mData.saveFileAs(path);
}

void MainWindow::drawGraphOrigin(QVector<double> data_x, QVector<double> data_y)
{
    ui->plotGraphOrigin->addGraph();
    ui->plotGraphOrigin->graph(0)->setData(data_x, data_y);

    ui->plotGraphOrigin->xAxis->setLabel("x");
    ui->plotGraphOrigin->yAxis->setLabel("y");

    ui->plotGraphOrigin->xAxis->setRange(-10, 10);
    ui->plotGraphOrigin->yAxis->setRange(-10, 10);
    ui->plotGraphOrigin->replot();
}

void MainWindow::drawGraphNew(QVector<double> data_x, QVector<double> data_y)
{
    ui->plotGraphNew->addGraph();
    ui->plotGraphNew->graph(0)->setPen(QPen(Qt::red));
    ui->plotGraphNew->graph(0)->setData(data_x, data_y);

    ui->plotGraphNew->xAxis->setLabel("x");
    ui->plotGraphNew->yAxis->setLabel("y");

    ui->plotGraphNew->xAxis->setRange(-10, 10);
    ui->plotGraphNew->yAxis->setRange(-10, 10);
    ui->plotGraphNew->replot();
}

void MainWindow::on_BT_changeData_clicked()
{
   this->func=ui->TE_function->toPlainText();
   mData.transform(func);
   drawGraphNew(mData.vector_x(), mData.vector_y());
}

void MainWindow::on_BT_changeData_2_clicked()
{
    QString name=ui->TE_newFile->toPlainText();
    if(name!="") {
        QString fileName=sPath;
        fileName.append("home/daniel/");
        fileName.append(name);
        fileName.append(".txt");
        saveFileAs(fileName);

        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0, "info", file.errorString());
        QTextStream in(&file);
        ui->TB_NewData->setText(in.readAll());
        file.close();
    }
}
