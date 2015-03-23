#-------------------------------------------------
#
# Project created by QtCreator 2015-03-12T02:28:39
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calendarKursovaya
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settingdialog.cpp \
    helpdialog.cpp \
    adddatadialog.cpp \
    textcongratulationdialog.cpp

HEADERS  += mainwindow.h \
    settingdialog.h \
    helpdialog.h \
    adddatadialog.h \
    textcongratulationdialog.h

FORMS    += mainwindow.ui \
    settingdialog.ui \
    helpdialog.ui \
    adddatadialog.ui \
    textcongratulationdialog.ui
