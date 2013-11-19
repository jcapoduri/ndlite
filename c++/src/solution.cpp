#include <QDebug>
#include "solution.h"
#include "app.h"

nd::solution::solution(const QJsonValue &initdata, QObject *parent) :
    QObject(parent)
{
    QJsonObject tmp_obj;
    QJsonArray  tmp_arr;
    _raw_data = initdata;
    int i, len;

    if (initdata.isObject()){
        tmp_obj = initdata.toObject();
        if (tmp_obj.contains("config")) _config = tmp_obj.value("config");
        if (tmp_obj.contains("meta")) _meta = tmp_obj.value("meta");
        if (tmp_obj.contains("objects")) _objects = tmp_obj.value("objects");
        if (tmp_obj.contains("relations")) _relations = tmp_obj.value("relations");
        if (tmp_obj.contains("storages")) _storages = tmp_obj.value("storages");
        if (tmp_obj.contains("apps")) _apps = tmp_obj.value("apps");
    };

    if (_objects.isArray()) {
        tmp_arr = _objects.toArray();
        len = tmp_arr.count();
        for (i = 0; i < len; i++) {
            tmp_obj = tmp_arr.at(i).toObject();
            _objectsMap.insert(tmp_obj.value("name").toString(), tmp_obj);
        };
    };

    if (_relations.isArray()) {
        tmp_arr = _relations.toArray();
        len = tmp_arr.count();
        for (i = 0; i < len; i++) {
            tmp_obj = tmp_arr.at(i).toObject();
            _relationsMap.insert(tmp_obj.value("name").toString(), tmp_obj);
        };
    };

    if (_storages.isArray()) {
        tmp_arr = _storages.toArray();
        len = tmp_arr.count();
        for (i = 0; i < len; i++) {
            tmp_obj = tmp_arr.at(i).toObject();
            _storageMap.insert(tmp_obj.value("name").toString(), tmp_obj);
        };
    };
}


nd::app *nd::solution::startApp(QString appName)
{
    nd::app *app = 0;
    QJsonObject  apps = _apps.toObject();
    if (apps.contains(appName)) {
        QJsonValue appdata = apps.value(appName);
        app = new nd::app(appdata, this);
    };

    return app;
}

QJsonObject nd::solution::getObjectInfo(const QString &name)
{
    return _objectsMap.value(name);
}

QJsonObject nd::solution::getRelationInfo(const QString &name)
{
    return _relationsMap.value(name);
}

QJsonObject nd::solution::getStorageInfo(const QString &name)
{
    return _storageMap.value(name);
}
