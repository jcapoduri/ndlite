#ifndef FIELD_H
#define FIELD_H

#include "ndlite_global.h"
#include <QObject>
#include <QVariant>
#include <QJsonArray>
#include <QJsonObject>

namespace nd {

class NDLITESHARED_EXPORT field : public QObject
{
    Q_OBJECT
public:
    static QString  ND_FIELDS;

    enum Type { String, Number, Decimal, Object, Array, Enum, Bool, Time, Date, Timestamp };
    Q_ENUMS(Type)

    explicit field(QJsonValue & initdata, QObject *parent = 0);

    // getters
    Type        type(){ return this->_type; }
    QString     name(){ return this->_name; }
    bool        isKey(){ return this->_isKey; }
    bool        isUnique(){ return this->_unique; }
    QVariant    defaultValue(){ return this->_default; }
    QVariant    value(){ return this->_value; }
    QJsonValue  storeValue();

    // setters
    void        setValue(QVariant val);
    void        toDefault(){ this->setValue(this->_default); }

signals:
    
public slots:

private:
    void        init();

    QJsonValue raw_data;

    Type        _type;
    QString     _name;
    bool        _isKey;
    bool        _unique;
    QVariant    _default;
    QList<QVariant> _enums;
    QString      _relationName;
    QString      _objectName;
    QVariant     _value;
};

}
#endif // FIELD_H
