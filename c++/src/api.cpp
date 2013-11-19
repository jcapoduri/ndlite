#include <QDebug>
#include "api.h"
#include "protoobject.h"

nd::api::api(QString baseurl, QObject *parent) :
    QObject(parent)
{
    jqXhr = new nd::ajax(baseurl);
}

nd::api::api(const nd::api &other)
{
    routeMap = other.routeMap;
    jqXhr = other.jqXhr;
}


nd::api::~api()
{
}

void nd::api::addMap(const QString name, const QString route)
{
    this->routeMap.insert(name, route);
}

void nd::api::delMap(const QString name)
{
    this->routeMap.remove(name);
}

bool nd::api::save(nd::protoObject *obj)
{
    int     id = 0;
    bool    ok = false;
    QString route = this->routeMap.value(obj->objectName());

    if (obj->hasOwnProperty("id")) id = obj->property("id").toInt();

    QJsonObject model = obj->toJSON();
    if (id == 0) {
        qDebug() << "POST!";
        id = this->jqXhr->post(route, model);
        ok = (id != 0);
    } else {
        qDebug() << "PUT!" << id;
        ok = this->jqXhr->put(route, id, model);
    };
    qDebug() << "last response:" << this->jqXhr->lastResponse();
    return ok;
}

bool nd::api::save(const QString &objname, const QJsonObject &obj)
{
    int     id = 0;
    bool    ok = false;
    QString route = this->routeMap.value(objname);

    if (obj.contains("id")) id = obj.value("id").toString().toInt();

    QJsonObject model = obj;

    if (id == 0) {
        qDebug() << "POST!";
        id = this->jqXhr->post(route, model);
        ok = (id != 0);
    } else {
        qDebug() << "PUT!" << id;
        ok = this->jqXhr->put(route, id, model);
    };
    return ok;
}

QJsonValue nd::api::get(const QString &objname, int id)
{
    QString route = this->routeMap.value(objname);
    if (id != 0) route.append(QString("/%1").arg(id));
    return this->jqXhr->get(route);
}

void nd::api::get(nd::protoObject *obj)
{
    QString objname = obj->objectName();
    QString route = this->routeMap.value(objname);
    QJsonValue value = this->jqXhr->get(route, obj->property("id").toInt());
    QJsonObject json_value = value.toObject();
    obj->fromJSON(json_value);
    qDebug() << "RESPONSE: " << this->jqXhr->lastResponse();
}

QJsonValue nd::api::get(const QString &objname, const QString &route)
{
    return jqXhr->get(route + "/" + objname);
}

bool nd::api::erase(nd::protoObject *obj)
{

}

bool nd::api::erase(const QString &objname, int id)
{
}

bool nd::api::erase(const QString &objname, const QJsonObject &obj)
{

}
