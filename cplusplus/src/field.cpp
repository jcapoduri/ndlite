#include <QVariant>
#include <QDateTime>
#include "field.h"

QString nd::field::ND_FIELDS = "[ \
{ \
    \"name\": \"id\", \
    \"isKey\": true, \
    \"unique\": true, \
    \"autoincremental\": true, \
    \"type\": \"number\" \
}, \
{ \
    \"name\": \"usrid\", \
    \"type\": \"number\" \
}, \
{ \
    \"name\": \"ctime\", \
    \"type\": \"timestamp\" \
}, \
{ \
    \"name\": \"mtime\", \
    \"type\": \"timestamp\" \
}, \
{ \
    \"name\": \"dtime\", \
    \"type\": \"timestamp\" \
}, \
{ \
    \"name\": \"deleted\", \
    \"type\": \"bool\" \
} \
]";

nd::field::field(QJsonValue & initdata, QObject *parent) :
    QObject(parent)
{
    raw_data = initdata;
    init();
}

QJsonValue nd::field::storeValue()
{
    //TODO
    return QJsonValue(this->value().toString());
}

void nd::field::setValue(QVariant val)
{
    //TODO
    this->_value = val;
}

void nd::field::init()
{
    QJsonObject tmp_obj;
    QString     tmp_string;

    tmp_obj = raw_data.toObject();
    this->_name = tmp_obj.value("name").toString();
    if (tmp_obj.contains("type")) {
        tmp_string = tmp_obj.value("type").toString();
        if (tmp_string == "string") this->_type = String;
        if (tmp_string == "decimal") this->_type = Decimal;
        if (tmp_string == "number") this->_type = Number;
        if (tmp_string == "bool") this->_type = Bool;
        if (tmp_string == "array") this->_type = Array;
        if (tmp_string == "time") this->_type = Time;
        if (tmp_string == "date") this->_type = Date;
        if (tmp_string == "timestamp") this->_type = Timestamp;
    } else return;

    if (tmp_obj.contains("default")) this->_default = tmp_obj.value("default").toVariant();
    else {
        switch (this->_type) {
            case String:
                this->_default = QString("");
                break;
            case Decimal:
                this->_default = 0.0;
                break;
            case Number:
                this->_default = 0;
                break;
            case Bool:
                this->_default = false;
                break;
            case Array:
                this->_default = QList<QVariant>();
                break;
            case Time:
                this->_default = QTime();
                break;
            case Date:
                this->_default = QDate();
                break;
            case Timestamp:
                this->_default = QDateTime();
                break;
            default:
                this->_default = -1;
        };
    };

    if (tmp_obj.contains("object_name")) this->_objectName = tmp_obj.value("object_name").toString();
    if (tmp_obj.contains("relation_name")) this->_relationName = tmp_obj.value("relation_name").toString();
}
