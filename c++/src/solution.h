#ifndef SOLUTION_H
#define SOLUTION_H

#include <QObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QStringList>
#include <QMap>

#include "ndlite_global.h"

namespace nd {

static QString nd_fields_str = R"([
{
    "name": "id",
    "isKey": true,
    "unique": true,
    "autoincremental": true,
    "type": "number"
},
{
    "name": "usrid",
    "type": "number"
},
{
    "name": "ctime",
    "type": "timestamp"
},
{
    "name": "mtime",
    "type": "timestamp"
},
{
    "name": "dtime",
    "type": "timestamp"
},
{
    "name": "deleted",
    "type": "bool"
}
])";

static QJsonArray nd_fields = QJsonDocument::fromJson(nd_fields_str.toLatin1()).array();

class NDLITESHARED_EXPORT app;

class NDLITESHARED_EXPORT solution : public QObject
{
    Q_OBJECT
public:
    solution(const QJsonValue &initdata, QObject *parent = 0);
    nd::app*        startApp(QString appName);
    QJsonObject getObjectInfo(const QString & name);
    QJsonObject getRelationInfo(const QString & name);
    QJsonObject getStorageInfo(const QString & name);

    QStringList allRelations() { return (QStringList)_relationsMap.keys(); }

signals:
    
public slots:
    
protected:
    QJsonValue                  _raw_data;
    QMap<QString, QJsonObject>  _objectsMap;
    QMap<QString, QJsonObject>  _relationsMap;
    QMap<QString, QJsonObject>  _storageMap;
    QJsonValue                  _meta;
    QJsonValue                  _config;
    QJsonValue                  _objects;
    QJsonValue                  _relations;
    QJsonValue                  _storages;
    QJsonValue                  _app;
    QJsonValue                  _apps;
    QJsonValue                  _map;

};


}
#endif // SOLUTION_H
