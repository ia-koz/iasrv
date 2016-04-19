QT += core network
QT -= gui

CONFIG += c++11

TARGET = iasrv
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.c++ \
    iasrv.c++ \
    iathr.c++

HEADERS += \
    iasrv.h++ \
    iathr.h++
