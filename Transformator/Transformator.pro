#-------------------------------------------------
#
# Project created by QtCreator 2017-07-12T13:07:29
#
#-------------------------------------------------

QT       += core gui
QT       += core gui xml printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Transformator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    transformator.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    transformator.h

FORMS    += mainwindow.ui
