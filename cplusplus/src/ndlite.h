#ifndef NDLITE_H
#define NDLITE_H

#include "ndlite_global.h"
#include <QJsonDocument>
#include <QObject>
#include "app.h"

namespace nd {

class NDLITESHARED_EXPORT Ndlite : public QObject
{
    friend class app;
    Q_OBJECT
public:
    Ndlite(QObject * parent = 0);
    /*template <class T = nd::app>
    static T* startApp (QJsonDocument & doc, QObject parent = 0);*/
private:
    static app* defaultApp;
};

template <class T>
T* startApp( QJsonDocument &doc, QObject *parent = 0)
{
    if (doc.isNull()) return 0;
    new T(doc.object(), parent);
}

}

#endif // NDLITE_H
