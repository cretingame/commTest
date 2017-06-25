QT += core
QT -= gui
QT += network

TARGET = commTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    customapp.cpp \
    eventdebug.cpp \
    sserver.cpp \
    sclient.cpp

HEADERS += \
    customapp.h \
    eventdebug.h \
    sserver.h \
    sclient.h

