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
    server.cpp \
    client.cpp

HEADERS += \
    customapp.h \
    eventdebug.h \
    server.h \
    client.h

