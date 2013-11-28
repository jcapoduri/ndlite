#ifndef NDLITE_H
#define NDLITE_H

#include "ndlite_global.h"
#include <QJsonDocument>
#include <QObject>
#include "app.h"


/*
* Declaration of a nd property and their functions
*/
#define ND_PROPERTY(Type, Name)  \
public:\
    Type* get##Name() const { \
        return this->##Name; \
    };	\
public slots:	\
    void set##Name( const Type & value) { \
        QObject * obj = sender();\
        if (obj) {\
            obj->blockSignals(true);\
        };\
        this->##Name = value;\
        emit on##Name(this->##Name);\
        if (obj) {\
            obj->blockSignals(false);\
        };\
    };\
public signals:\
    void	on##Name(Type & value);\
protected:\
    Type*	Name;\
    Q_PROPERTY(Type Name READ get##Name WRITE set##Name NOTIFY on##Name)


#define ND_LIST_PROPERTY(Type, Name)  \
public:\
    QList< (Type)*> getAll##Name() const { \
        return Name; \
    };	\
public slots:	\
    void	addTo##Name( const Type & value) {\
        QObject * obj = sender();\
        if (obj) {\
            obj->blockSignals(true);\
        };\
        this->##Name << value;\
        emit on##Name();\
        if (obj) {\
            obj->blockSignals(false);\
        };\
    };\
    void	removeFrom##Name( const Type & value) {\
        QObject * obj = sender();\
        if (obj) {\
            obj->blockSignals(true);\
        };\
        this->##Name.remove(value);\
        emit on##Name(value);\
        if (obj) {\
            obj->blockSignals(false);\
        };\
    };\
public signals:\
    void	on##Name(Type & value);\
protected:\
    QList< (Type)*>	Name;


/*
* Declaration of binding between property and a widget
*/
#define ND_BIND(Property, Widget, Signal, Slot) \
connect( (Widget), SIGNAL( (Signal) ),  (Property), SLOT( (Slot) ) );\
connect( (Property), SIGNAL ( on##Property ), (Widget), SLOT( (Slot) ) );

namespace nd {

template <class T>
T* startApp( QJsonDocument &doc, QObject *parent = 0)
{
    if (doc.isNull()) return 0;
    QJsonValue obj(doc.object());
    new T(obj, parent);
}

}

#endif // NDLITE_H
