#include "app.h"
#include "protoobject.h"
#include <QStringList>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

nd::app* nd::app::default_app = 0;

nd::modelDefinition* nd::app::model(const QString &name) {
    if (nd::app::default_app == 0) return 0;
    return nd::app::default_app->getModel(name);
}

nd::app::app(QJsonValue &initdata, nd::solution *sol, QObject *parent) :
    QObject(parent)
{
    raw_data = initdata;
    solution = sol;

    //set up storage
    QJsonArray storage = raw_data.toObject().value("storage").toArray();
    QString storage_name = storage.at(0).toString();

    QJsonObject storage_info = solution->getStorageInfo(storage_name);
    define(app::storage, storage_name, storage_info);
    QJsonObject map_info = raw_data.toObject().value("map").toObject();

    // init API
    manager = new nd::api(storage_info.value("url").toString() + storage_info.value("base_uri").toString());

    // load relation
    QStringList keys;
    int i, length;
    keys = solution->allRelations();
    length = keys.count();
    for (i = 0; i < length; i++) {
        define(relation, keys.at(i), solution->getRelationInfo(keys.at(i)));
    };
    length = map_info.count();
    keys = map_info.keys();

    for (i = 0; i < length; i++) {
        QString entity = keys.at(i);
        QJsonObject entity_obj = solution->getObjectInfo(entity);

        manager->addMap(entity, map_info.value(entity).toString());
        define(object, entity, entity_obj);
    };

    nd::app::default_app = this;
}

nd::app::~app()
{
    // clean the memory
}

void nd::app::loadData(const QJsonValue &value)
{
    raw_data = value;

}

void nd::app::define(define_option type, const QString &objname, QJsonObject initdata) {
    switch (type) {
    case storage:
        storages.insert(objname, initdata);
        break;
    case relation:
        //qDebug() << "INSERT INTO RELATION" << objname << initdata;
        relations.insert(objname, initdata);
        break;
    case object:
        objects.insert(objname, initdata);
        models.insert(objname, new modelDefinition(objname, initdata, this));
        break;
    default:
        break;
    }
}

QJsonObject nd::app::getDefinition(nd::app::define_option type, const QString &objname)
{
    switch (type) {
    case storage:
        return this->storages.value(objname);
        break;
    case relation:
        //qDebug() << "GET RELATION" << objname << this->relations.value(objname) << relations.contains(objname);
        //qDebug() << relations;
        return this->relations.value(objname);
        break;
    case object:
        return this->objects.value(objname);
        break;
    default:
        return QJsonObject();
        break;
    }
}

/*
nd::protoObject* nd::app::createObject(const QString &objname, QJsonObject initdata)
{
    protoObject *obj = new protoObject(this);
    QJsonObject json = this->solution->getObjectInfo(objname);
    QJsonValue value;
    obj->setObjectName(objname);
    int i, length;

    QJsonArray fields = nd::nd_fields;
    length = fields.count();
    for (i = 0; i < length; i++) {
        value = fields.at(i);
        setField(value.toObject(), obj);
    };

    fields = json.value("fields").toArray();
    length = fields.count();
    for (i = 0; i < length; i++) {
        value = fields.at(i);
        setField(value.toObject(), obj);
    };

    if (!initdata.isEmpty()) {
        QList<QByteArray> list = this->dynamicPropertyNames();
        int i = 0, length = list.count();

        for (; i < length; i++) {

        };
    };

    return obj;
}

nd::protoObject nd::app::createRelation(const QString &objname)
{
    protoObject obj(this);
    QJsonObject json = this->solution->getRelationInfo(objname);
    obj.fromJSON(json);
    return obj;
}

nd::protoObject nd::app::createStorage(const QString &objname)
{
    protoObject obj(this);
    QJsonObject json = this->solution->getStorageInfo(objname);    
    obj.fromJSON(json);
    return obj;
}
*/
nd::api *nd::app::api()
{
    return manager;
}

void nd::app::setField(const QJsonObject &field, nd::protoObject *obj)
{
    QString type = field.value("type").toString();
    QString name = field.value("name").toString();

    if (type.toLower() == "object" || type.toLower() == "array") {
        if (type.toLower() == "object") {
            obj->setProperty(name.toLatin1(), QVariant::fromValue((new protoObject(this))));
        } else {
            QList<protoObject*> list;
            obj->setProperty(name.toLatin1(), QVariant::fromValue(list));
        };
    } else {
        obj->setProperty(name.toLatin1(), QVariant(field.value("default")));
    };
}

void nd::app::addRelation(const QJsonObject &obj)
{
    QJsonArray fields = obj.value("fields").toArray();
    int i = 0, len = fields.count();

    for(; i < len; i++) {
        QJsonObject field = fields.at(i).toObject();
        if (field.value("type").toString().toLower() == "array") {
            QString name = field.value("relation_name").toString();
            //qDebug() << name << solution->getRelationInfo(name);
            define(relation, name, solution->getRelationInfo(name));
        };
    };
}
