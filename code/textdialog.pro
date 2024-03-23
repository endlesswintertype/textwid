#-------------------------------------------------
#
# Project created by QtCreator 2023-10-20T09:06:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = textdialog
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    recordselection.cpp \
    talkDialog.cpp \
    DialogChooseNew.cpp

HEADERS  += mainwindow.h \
    recordselection.h \
    talkDialog.h \
    DialogChooseNew.h \
    eventinfo.h

FORMS    += mainwindow.ui \
    talkDialog.ui \
    DialogChooseNew.ui

