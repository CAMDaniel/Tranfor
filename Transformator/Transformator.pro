#-------------------------------------------------
#
# Project created by QtCreator 2017-07-12T13:07:29
#
#-------------------------------------------------

QT       += core gui
QT       += script
QT       += core gui xml printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Transformator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    transformator.cpp \
    echmetqtengine.cpp \
    ascloader.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    transformator.h \
    echmetqtengine.h \
    ascloader.h

FORMS    += mainwindow.ui
