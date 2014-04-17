#-------------------------------------------------
#
# Project created by QtCreator 2014-04-15T00:35:05
#
#-------------------------------------------------
QT       += core

QT       -= gui

TARGET = QTokenizer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += $$PWD/../QTokenizer

SOURCES += main.cpp

LIBS += -L$$OUT_PWD/../QTokenizer -lQTokenizer
