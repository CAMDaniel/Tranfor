#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setRoot("/");
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

void MainWindow::loadDataFromFile(void)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    QStringList list;
    QStringList model;
    while(!in.atEnd()) {
        QString line = in.readLine();
        list = line.split(";");
        model.append(list[0]);
        model.append(list[1]);
    }

    int data_len=model.size()/2;
//    QString tmp=QString::number(data_len);
//    ui->TE_function->setText(tmp);
    data_x.resize(data_len);
    data_y.resize(data_len);
    data_z.resize(data_len);

    for(int i=0; i<model.size(); i+=2) {
        data_x[i/2]=model[i].toDouble();
        data_y[i/2]=model[i+1].toDouble();
    }

    file.close();
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

void MainWindow::on_LV_showFiles_clicked(const QModelIndex &index)
{
   QString Path=dirModel->fileInfo(index).absoluteFilePath();
   QFile file(Path);
   this->filePath=Path;
   if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info", file.errorString());
   QTextStream in(&file);
   ui->TE_OriginFile->setText(Path);
   ui->TB_OriginData->setText(in.readAll());
   file.close();

   loadDataFromFile();
   convertDataFromFile(Path);
   MainWindow::makePlot();
}

void MainWindow::convertDataFromFile(QString Path)
{
    //TODO
    QString fileName="/home/daniel/ahoj.txt";
    QFile file(fileName);
    if (file.open(QIODevice::ReadWrite))
    {
        QTextStream in(&file);
        in << "something" << endl;

        for (int i=0; i<data_x.size(); i++) {
            QString x=QString::number(data_x[i]);
            QString z=QString::number(data_z[i]);
            in<<x<<";"<<z<<endl;
        }
        ui->TB_NewData->setText(in.readAll());
        file.close();
    }
}

void MainWindow::GenerateData(int sizeVec)
{
    data_x.resize(sizeVec);
    data_y.resize(sizeVec);
    data_z.resize(sizeVec);
    for (int i=0; i<sizeVec; ++i) {
        this->data_x[i]=i/50.0-1;
        this->data_y[i]=data_x[i]*data_x[i];
        this->data_z[i]=sin(data_x[i]);
    }
}

void MainWindow::setGraphOrigin(void)
{
    ui->plotGraphOrigin->addGraph();
    ui->plotGraphOrigin->graph(0)->setData(data_x, data_y);

    ui->plotGraphOrigin->xAxis->setLabel("x");
    ui->plotGraphOrigin->yAxis->setLabel("y");

    ui->plotGraphOrigin->xAxis->setRange(-10, 10);
    ui->plotGraphOrigin->yAxis->setRange(-10, 10);
    ui->plotGraphOrigin->replot();
}

void MainWindow::setGraphNew(void)
{
    ui->plotGraphNew->addGraph();
    ui->plotGraphNew->graph(0)->setData(data_x, data_z);

    ui->plotGraphNew->xAxis->setLabel("x");
    ui->plotGraphNew->yAxis->setLabel("y");

    ui->plotGraphNew->xAxis->setRange(-10, 10);
    ui->plotGraphNew->yAxis->setRange(-10, 10);
    ui->plotGraphNew->replot();
}

void MainWindow::makePlot(void)
{
    setGraphOrigin();
    setGraphNew();
}
