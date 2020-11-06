#-------------------------------------------------
#
# Project created by QtCreator 2020-09-27T11:46:50
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sgz_ejoy
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        adb.cpp \
        configsave.cpp \
        device.cpp \
        dialog.cpp \
        main.cpp \
        mainwindow.cpp \
        netresdata.cpp \
        position.cpp \
        quickconscript.cpp \
        sgz.cpp \
        waitmainthread.cpp \
        workthread.cpp

HEADERS += \
        adb.h \
        configsave.h \
        device.h \
        dialog.h \
        mainwindow.h \
        netresdata.h \
        position.h \
        quickconscript.h \
        sgz.h \
        waitmainthread.h \
        workthread.h

FORMS += \
        dialog.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
