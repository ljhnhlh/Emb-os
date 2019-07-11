#-------------------------------------------------
#
# Project created by QtCreator 2018-07-22T09:39:33
#
#-------------------------------------------------

QT       += core gui network
#QT +=   sql
LIBS += -lsqlite3

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = camera
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    camera.cpp \
    loginwindow.cpp

HEADERS  += mainwindow.h \
    camera.h \
    loginwindow.h

FORMS    += \
    mainwindow.ui \
    loginwindow.ui

