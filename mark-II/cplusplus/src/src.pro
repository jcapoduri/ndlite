#-------------------------------------------------
#
# Project created by QtCreator 2013-06-08T20:25:19
#
#-------------------------------------------------

QT       += widgets network script

TARGET = ndlite
TEMPLATE = lib
DESTDIR = ../bin
MOC_DIR = ../obj
OBJECTS_DIR = ../obj

DEFINES += NDLITE_LIBRARY

SOURCES += ndlite.cpp \
    object.cpp \
    relation.cpp \
    storage.cpp \
    field.cpp \
    app.cpp \
    storageEngines/apistorage.cpp

HEADERS += ndlite.h\
        ndlite_global.h \
    object.h \
    relation.h \
    storage.h \
    field.h \
    app.h \
    storageEngines/apistorage.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
