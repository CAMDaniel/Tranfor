/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *plotGraphOrigin;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QTextBrowser *TB_readAsText;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTreeView *TV_fileSystem;
    QListView *LV_showFiles;
    QTreeView *TV_dataFiles;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QPushButton *BT_changeData;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LB_origin;
    QLabel *LB_new;
    QCustomPlot *plotGraphNew;
    QLabel *LB_orginGraph;
    QLabel *LB_newGraph;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEdit_2;
    QPushButton *BT_changeData_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1391, 716);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        plotGraphOrigin = new QCustomPlot(centralWidget);
        plotGraphOrigin->setObjectName(QStringLiteral("plotGraphOrigin"));
        plotGraphOrigin->setGeometry(QRect(780, 40, 591, 271));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(420, 110, 341, 511));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(gridLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 2, 1, 1);

        TB_readAsText = new QTextBrowser(gridLayoutWidget);
        TB_readAsText->setObjectName(QStringLiteral("TB_readAsText"));

        gridLayout->addWidget(TB_readAsText, 0, 1, 1, 1);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 371, 611));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        TV_fileSystem = new QTreeView(verticalLayoutWidget);
        TV_fileSystem->setObjectName(QStringLiteral("TV_fileSystem"));

        verticalLayout->addWidget(TV_fileSystem);

        LV_showFiles = new QListView(verticalLayoutWidget);
        LV_showFiles->setObjectName(QStringLiteral("LV_showFiles"));

        verticalLayout->addWidget(LV_showFiles);

        TV_dataFiles = new QTreeView(verticalLayoutWidget);
        TV_dataFiles->setObjectName(QStringLiteral("TV_dataFiles"));

        verticalLayout->addWidget(TV_dataFiles);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(420, 10, 341, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(horizontalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout->addWidget(textEdit);

        BT_changeData = new QPushButton(horizontalLayoutWidget);
        BT_changeData->setObjectName(QStringLiteral("BT_changeData"));

        horizontalLayout->addWidget(BT_changeData);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(420, 80, 341, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        LB_origin = new QLabel(horizontalLayoutWidget_2);
        LB_origin->setObjectName(QStringLiteral("LB_origin"));

        horizontalLayout_2->addWidget(LB_origin);

        LB_new = new QLabel(horizontalLayoutWidget_2);
        LB_new->setObjectName(QStringLiteral("LB_new"));

        horizontalLayout_2->addWidget(LB_new);

        plotGraphNew = new QCustomPlot(centralWidget);
        plotGraphNew->setObjectName(QStringLiteral("plotGraphNew"));
        plotGraphNew->setGeometry(QRect(780, 340, 591, 281));
        LB_orginGraph = new QLabel(centralWidget);
        LB_orginGraph->setObjectName(QStringLiteral("LB_orginGraph"));
        LB_orginGraph->setGeometry(QRect(780, 9, 121, 31));
        LB_newGraph = new QLabel(centralWidget);
        LB_newGraph->setObjectName(QStringLiteral("LB_newGraph"));
        LB_newGraph->setGeometry(QRect(780, 310, 121, 31));
        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(420, 40, 341, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        textEdit_2 = new QTextEdit(horizontalLayoutWidget_3);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        horizontalLayout_3->addWidget(textEdit_2);

        BT_changeData_2 = new QPushButton(horizontalLayoutWidget_3);
        BT_changeData_2->setObjectName(QStringLiteral("BT_changeData_2"));

        horizontalLayout_3->addWidget(BT_changeData_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1391, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        BT_changeData->setText(QApplication::translate("MainWindow", "convert", 0));
        LB_origin->setText(QApplication::translate("MainWindow", "Origin data", 0));
        LB_new->setText(QApplication::translate("MainWindow", "New data", 0));
        LB_orginGraph->setText(QApplication::translate("MainWindow", "Origin graph", 0));
        LB_newGraph->setText(QApplication::translate("MainWindow", "New graph", 0));
        BT_changeData_2->setText(QApplication::translate("MainWindow", "save file", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
