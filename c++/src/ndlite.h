#ifndef NDLITE_H
#define NDLITE_H

#include "ndlite_global.h"
#include <QJsonDocument>
#include <QObject>
#include "app.h"

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
