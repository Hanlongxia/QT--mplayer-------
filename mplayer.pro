#-------------------------------------------------
#
# Project created by QtCreator 2021-09-14T15:02:16
#
#-------------------------------------------------

QT       += core gui

CONFIG += C++11
QMAKE_CXXFLAGS += -std=c++0x
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mplayer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
SOURCES += \
        main.cpp \
        widget.cpp \
    volume.cpp \
    tablewidget.cpp \
    song_listtable.cpp \
    like_listwidget.cpp

HEADERS += \
        widget.h \
    volume.h \
    tablewidget.h \
    song_listtable.h \
    headr.h \
    like_listwidget.h

FORMS += \
        widget.ui \
    volume.ui \
    tablewidget.ui \
    song_listtable.ui \
    like_listwidget.ui

RESOURCES += \
    file01.qrc
