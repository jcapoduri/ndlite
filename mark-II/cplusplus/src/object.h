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
    object(const object & other);
    object();
    object & operator =(const object & other);
    ~object();

    bool        loadJSON(QJsonValue value); //deprecated
    //QByteArray  toJSON();
    QJsonObject toJSON();


    field*      getField(QString name);
    void        setValue(const QString field, const QVariant value);
    QVariant    value(const QString field);
    QString     name();

private:    
    void            init();
    void            addFields(QJsonArray &fields);


    QJsonValue      raw_data;
    QMap<QString, field*>   _key_fields;
    QMap<QString, field*>   _fields;
    bool            nd_fields;
    QString         inherit_obj;
};

}

Q_DECLARE_METATYPE(nd::object)
Q_DECLARE_METATYPE(QList<nd::object*>)
Q_DECLARE_METATYPE(QList<nd::object*>*)

#endif // OBJECT_H
