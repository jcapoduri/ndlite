#include "object.h"




nd::object::object(QJsonValue &initdata, QObject *parent) : QObject(parent)
{
    raw_data = initdata;

}

nd::object::~object()
{
    /*qDeleteAll(this->_fields.begin(), this->_fields.end());
    qDeleteAll(this->_key_fields.begin(), this->_key_fields.end());*/
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
        if (tmp_field->isKey()) _key_fields.append(tmp_field);
        else _fields.append(tmp_field);
    };
}

