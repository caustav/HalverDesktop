#-------------------------------------------------
#
# Project created by QtCreator 2016-09-19T14:09:32
#
#-------------------------------------------------

QT       += core gui

QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Halver
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sender.cpp \
    receiver.cpp \
    filemeatadata.cpp \
    filesync.cpp \
    serversocket.cpp \
    qtcpsocketext.cpp

HEADERS  += mainwindow.h \
    sender.h \
    receiver.h \
    filemeatadata.h \
    filesync.h \
    filemetadata.h \
    serversocket.h \
    qtcpsocketext.h \
    socketcapsule.h \

FORMS    += mainwindow.ui
