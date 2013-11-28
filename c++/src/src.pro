#-------------------------------------------------
#
# Project created by QtCreator 2013-06-08T20:25:19
#
#-------------------------------------------------

QT       += widgets network
CONFIG   += c++11

TARGET = ndlite
TEMPLATE = lib
DESTDIR = ../bin
MOC_DIR = ../obj
OBJECTS_DIR = ../obj

DEFINES += NDLITE_LIBRARY

SOURCES += ndlite.cpp \
    app.cpp \
    protoobject.cpp \
    ajax.cpp \
    api.cpp \
    solution.cpp \
    model.cpp \
    modeldefinition.cpp \
    modelexception.cpp

HEADERS += ndlite_global.h \
    app.h \
    protoobject.h \
    ajax.h \
    api.h \
    solution.h \
    model.h \
    modeldefinition.h \
    modelexception.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
