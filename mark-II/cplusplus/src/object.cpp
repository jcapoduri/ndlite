#include "object.h"
#include <QStringList>

nd::object::object(QJsonValue &initdata, QObject *parent) : QObject(parent)
{
    raw_data = initdata;

}

nd::object::object(const nd::object &other)
{
}

nd::object::object()
{
}

nd::object &nd::object::operator =(const nd::object &other)
{

}

nd::object::~object()
{
    /*qDeleteAll(this->_fields.begin(), this->_fields.end());
    qDeleteAll(this->_key_fields.begin(), this->_key_fields.end());*/
}

bool nd::object::loadJSON(QJsonValue value)
{
    QJsonObject data = value.toObject();
    QStringList keys = data.keys();
    field* tmp_field;
    for (int i = 0; i < keys.count(); i++) {
        if (this->_fields.contains(keys.at(i))) {
            tmp_field = this->_fields.value(keys.at(i));
            if (tmp_field->type() != field::Array) {
                tmp_field->setValue(data.value(keys.at(i)));
            }else{

            };
        };
    };
    return true;
}

QJsonObject nd::object::toJSON()
{
    QJsonObject obj;
    QStringList keys = this->_fields.keys();
    nd::field*  tmp_field;
    int         len = keys.length();
    int         i, len2;

    for (int i = 0; i < len; i++) {
        tmp_field = this->_fields.value(keys.at(i));
        obj.insert(keys.at(i), tmp_field->toJSON());
        /*if (tmp_field->type() != field::Array) {
            //tmp_field->setValue(data.value(keys.at(i)));
            QJsonValue val = QJsonValue::fromVariant(tmp_field->value());
            obj.insert(keys.at(i), val);
        }else{
            QJsonArray tmp_arr;
            //QList<nd::object*>* list = tmp_field->value().value<QList <nd::object*>* >();
            len2 = list->length();
            for(i = 0; i < len2; i++) {
                obj = QJsonDocument::fromJson(list->at(i)->toJSON()).object();
                tmp_arr.append(obj);
            };
            obj.insert(keys.at(i), tmp_arr);
        };*/
    };
    return obj;
}

nd::field* nd::object::getField(QString name)
{
    if (this->_fields.contains(name)) {
        return this->_fields.value(name);
    } else return 0;
}

void nd::object::setValue(const QString field, const QVariant value)
{
    nd::field* tmp_field;
    if (this->_fields.contains(field)) {
        tmp_field = this->_fields.value(field);
        tmp_field->setValue(value);
    }
}

QVariant nd::object::value(const QString field)
{
    nd::field* tmp_field;
    if (this->_fields.contains(field)) {
        tmp_field = this->_fields.value(field);
        return tmp_field->value();
    };
    return QVariant();
}

QString nd::object::name()
{
    return raw_data.toObject().value("name").toString();
}

void nd::object::init()
{
    QJsonObject tmp_obj;
    QJsonArray  tmp_arr;
    QJsonDocument tmp_doc;

    tmp_obj = raw_data.toObject();
    nd_fields = tmp_obj.value("nd_fields").toBool();
    inherit_obj = tmp_obj.value("inherit").toString();

    tmp_arr = tmp_obj.value("fields").toArray();
    addFields(tmp_arr);

    if (nd_fields){
        tmp_doc.fromJson(field::ND_FIELDS.toLatin1());
        tmp_arr = tmp_doc.array();
        addFields(tmp_arr);
    }
}

void nd::object::addFields(QJsonArray &fields)
{
    QJsonValue  tmp_obj;
    field*      tmp_field;
    uint        len, i;

    len = fields.count();
    for (i = 0; i < len; i++) {
        tmp_obj = fields.at(i);
        tmp_field = new field(tmp_obj, this);
        this->_fields.insert(tmp_field->name(), tmp_field);
        if (tmp_field->isKey()) _key_fields.insert(tmp_field->name(), tmp_field);
    };
}

