#-------------------------------------------------
#
# Project created by QtCreator 2016-09-12T11:28:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapCreator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    advancedqlabel.cpp \
    sizemapdialog.cpp \
    gamemap.cpp \
    textureqlabel.cpp

HEADERS  += mainwindow.h \
    advancedqlabel.h \
    sizemapdialog.h \
    gamemap.h \
    textureqlabel.h

FORMS    += mainwindow.ui \
    sizemapdialog.ui

RESOURCES += \
    resource.qrc
