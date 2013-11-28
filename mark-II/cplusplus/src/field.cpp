#include <QVariant>
#include <QDateTime>
#include "field.h"
#include "object.h"

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
    this->_value = new QVariant();
    sealed = true;
    init();
}

nd::field::field(const nd::field &f)
{
}

nd::field::field()
{
    this->_value = new QVariant();
    sealed = true;
}

nd::field::~field()
{
    delete this->_value;
}

bool nd::field::isSealed()
{
    return this->sealed;
}

QJsonValue nd::field::toJSON()
{
    nd::field::Type type = this->_type;
    switch (type) {
        case nd::field::Time:
            {
                //this->_value->setValue(QTime::fromString(val.toString()));
                QJsonValue value = QJsonValue::fromVariant(this->value());
                return value;
                break;
            }
        case nd::field::Array:
            {
                //json array
                QList<nd::object*>* list = this->_value->value< QList <nd::object*>* >();

                break;
            }

        case nd::field::Date:
            {
                //this->_value->setValue(QDate::fromString(val.toString()));
                QJsonValue value = QJsonValue::fromVariant(this->value());
                return value;
                break;
            }
        case nd::field::Timestamp:
            {
                //this->_value->setValue(QDateTime::fromString(val.toString()));
                QJsonValue value = QJsonValue::fromVariant(this->value());
                return value;
                break;
            }
        default:
            {
                //this->_value->setValue(val);
                return QJsonValue();
                break;
            }
    };
}

void nd::field::setValue(QVariant val)
{
    //TODO
    switch (this->_type) {
        case Array:
            //json array
            /*QJsonArray list = val.toJsonArray();
            this->_value = QList<QVariant>();*/
            break;
        case Time:
            this->_value->setValue(QTime::fromString(val.toString()));
            break;
        case Date:
            this->_value->setValue(QDate::fromString(val.toString()));
            break;
        case Timestamp:
            this->_value->setValue(QDateTime::fromString(val.toString()));
            break;
        default:
            this->_value->setValue(val);
    };
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

void nd::field::seal()
{
    this->sealed = true;
}
