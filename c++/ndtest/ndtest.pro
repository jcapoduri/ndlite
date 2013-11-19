#-------------------------------------------------
#
# Project created by QtCreator 2013-10-07T18:14:32
#
#-------------------------------------------------

QT       += network testlib

QT       -= gui

TARGET = tst_ndtesttest
CONFIG   += console
CONFIG   += c++11

DESTDIR = ../bin
MOC_DIR = ../bin
OBJECTS_DIR = ../bin

TEMPLATE = app


SOURCES += tst_ndtesttest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

# libraries
DEPENDPATH  += ../src
INCLUDEPATH += ../src
INCLUDEPATH += ../bin
INCLUDEPATH += ../
LIBS += -L ../bin -lndlite
