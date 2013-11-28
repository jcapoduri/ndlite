#ifndef APP_H
#define APP_H

#include "ndlite_global.h"
#include <QObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>
#include <QString>
#include "storage.h"

namespace nd {

class storage;
class NDLITESHARED_EXPORT app : public QObject
{
    Q_OBJECT
public:
    app(QJsonValue & initdata, QObject *parent = 0);
    ~app();
    void    setApp(QString appname);

    object*     getObject(const QString name);
    bool        loadObject(object* obj, QJsonValue & val);
    bool        loadRelation(field* field, QJsonValue & val);
    QString     storageMap(object & obj);
    nd::storage* const    storage(){ return this->_storage; }
signals:
    
public slots:

protected:

    QString                     appname;
    QJsonValue                  _raw_data;
    nd::storage*                _storage;
    QMap<QString, QJsonObject>  _objectsMap;
    QMap<QString, QJsonObject>  _relationsMap;
    QMap<QString, QJsonObject>  _storageMap;
    QMap<QString, QString>      _objectMapping;
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

#endif // APP_H
