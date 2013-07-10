#ifndef OBJECT_H
#define OBJECT_H

#include "ndlite_global.h"
#include <QObject>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>
#include "field.h"

namespace nd {

class NDLITESHARED_EXPORT object : public QObject
{
    Q_OBJECT

public:
    object(QJsonValue & initdata, QObject * parent = 0);
    ~object();

private:    
    void            init();
    void            addFields(QJsonArray &fields);

    QJsonValue      raw_data;
    QList<field*>   _key_fields;
    QList<field*>   _fields;
    bool            nd_fields;
    QString         inherit_obj;
};

}

#endif // OBJECT_H
