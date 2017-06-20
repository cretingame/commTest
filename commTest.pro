QT += core
QT -= gui

TARGET = commTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    customapp.cpp \
    eventdebug.cpp

HEADERS += \
    customapp.h \
    eventdebug.h

