#ifndef STORAGE_H
#define STORAGE_H

#include "ndlite_global.h"
#include <QJsonObject>
#include "object.h"
#include "relation.h"
#include "app.h"

namespace nd {

class app;

class NDLITESHARED_EXPORT storage : public QObject
{
    Q_OBJECT

public:    
    storage(QJsonValue & initdata, nd::app * application, QObject * parent = 0);
    virtual bool commit(object & obj) = 0;
    virtual bool update(object & obj, quint16 id) = 0;
    virtual bool erase(object & obj, quint16 id) = 0;
    virtual bool unerase(object & obj, quint16 id) = 0;
    virtual bool touch(object & obj, quint16 id) = 0;

    virtual bool commit(relation & rel) = 0;
    virtual bool update(relation & rel) = 0;

    virtual void beginTransaction() {}
    virtual void commitTransaction() {}
    virtual void rollbackTransaction() {}

protected:
    QJsonValue              raw_data;
    app*                    _app;
};

}
#endif // STORAGE_H
