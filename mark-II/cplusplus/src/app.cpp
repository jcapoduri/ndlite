#include "app.h"
#include "storageEngines/apistorage.h"
#include <QStringList>

nd::app::app(QJsonValue &initdata, QObject *parent) :
    QObject(parent)
{
    QJsonObject tmp_obj;
    _raw_data = initdata;
    if (initdata.isObject()){
        tmp_obj = initdata.toObject();
        if (tmp_obj.contains("config")) _config = tmp_obj.value("config");
        if (tmp_obj.contains("meta")) _meta = tmp_obj.value("meta");
        if (tmp_obj.contains("objects")) _objects = tmp_obj.value("objects");
        if (tmp_obj.contains("relations")) _relations = tmp_obj.value("relations");
        if (tmp_obj.contains("storages")) _storages = tmp_obj.value("storage");
        if (tmp_obj.contains("apps")) _apps = tmp_obj.value("apps");
    };
}

nd::app::~app()
{
    // clean the memory
}

void nd::app::setApp(QString appname)
{
    QJsonArray      tmp_arr;
    QJsonValue      tmp_val;
    QJsonObject     tmp_obj;
    uint            len, i;

    this->appname = appname;
    _app = _apps.toObject().value(appname);

    //check each object and add a objects into the map
    tmp_arr = _objects.toArray();
    len = tmp_arr.count();
    for (i = 0; i < len; i++) {
        tmp_obj = tmp_arr.at(i).toObject();
        _objectsMap.insert(tmp_obj.value("name").toString(), tmp_obj);
    };

    //check each object and add a relation into the map
    tmp_arr = _relations.toArray();
    len = tmp_arr.count();
    for (i = 0; i < len; i++) {
        tmp_obj = tmp_arr.at(i).toObject();
        _relationsMap.insert(tmp_obj.value("name").toString(), tmp_obj);
    };

    //object mapping
    tmp_obj = _app.toObject().value("map").toObject();
    QJsonObject::iterator it;// = tmp_obj.begin();
    for (it = tmp_obj.begin(); it != tmp_obj.end(); ++it) {
        _objectMapping.insert(it.key(), it.value().toString());
    }

    tmp_arr = _storages.toArray();
    len = tmp_arr.count();
    for (i = 0; i < len; i++) {
        tmp_obj = tmp_arr.at(i).toObject();
        _storageMap.insert(tmp_obj.value("name").toString(), tmp_obj);
    };

    //check for storage and start it
    tmp_val = _app.toObject().value("storage").toArray().at(0);
    tmp_val = _storageMap.value(tmp_val.toString());
    _storage = new apiStorage(tmp_val, this);

    _map = _app.toObject().value("map");
}

nd::object *nd::app::getObject(const QString name)
{
    nd::object *obj = 0;
    QJsonValue tmp_value;

    if(this->_objectsMap.contains(name)){
        tmp_value = QJsonValue(this->_objectsMap.value(name));
        obj = new nd::object(tmp_value, this);
    };
    return obj;
}

bool nd::app::loadObject(nd::object *obj, QJsonValue &val)
{
    QJsonObject data = val.toObject();
    QJsonValue tmp_value;
    QStringList keys = data.keys();
    nd::field* tmp_field;
    for (int i = 0; i < keys.count(); i++) {
        tmp_field = obj->getField(keys.at(i));
        if (!tmp_field) continue;
        if (tmp_field->type() != field::Array) {
            tmp_field->setValue(data.value(keys.at(i)));
        } else {
            tmp_value = data.value(keys.at(i));
            this->loadRelation(tmp_field, tmp_value);
        };
    };
    return true;
}

bool nd::app::loadRelation(nd::field *field, QJsonValue &val)
{
    object* obj;
    QJsonArray data = val.toArray();
    QJsonObject relation = this->_relationsMap.value(field->getRelationName());
    QJsonValue tmp_value;
    QString object_name = relation.value(field->getRelationName()).toString();
    QList<object*> list;
    bool ok = true;

    for (int i = 0; i < data.count(); i++) {
        obj = this->getObject(object_name);
        tmp_value = data.at(i);
        ok = ok && this->loadObject(obj, tmp_value);
        list.append(obj);
    };
    QVariant tmp_variant = QVariant::fromValue(list);
    field->setValue(tmp_variant);
    return ok;
}

QString nd::app::storageMap(nd::object &obj)
{
    return this->_objectMapping.value(obj.name());
}

