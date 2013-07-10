#ifndef STORAGE_H
#define STORAGE_H

#include "ndlite_global.h"
#include <QJsonObject>
#include "object.h"
#include "relation.h"

namespace nd {

class NDLITESHARED_EXPORT storage : public QObject
{
    Q_OBJECT

public:    
    storage(QJsonValue & initdata, QObject * parent = 0);
    virtual bool commit(nd::object & obj) = 0;
    virtual bool update(nd::object & obj) = 0;
    virtual bool erase(nd::object & obj) = 0;
    virtual bool unerase(nd::object & obj) = 0;
    virtual bool touch(nd::object & obj) = 0;

    virtual bool commit(nd::relation & rel) = 0;
    virtual bool update(nd::relation & rel) = 0;

    virtual void beginTransaction() {}
    virtual void commitTransaction() {}
    virtual void rollbackTransaction() {}

private:
    QJsonValue raw_data;
};

}
#endif // STORAGE_H
