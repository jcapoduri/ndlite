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

class NDLITESHARED_EXPORT app : public QObject
{
    Q_OBJECT
public:
    explicit app(QJsonValue & initdata, QObject *parent = 0);
    ~app();
    
signals:
    
public slots:

private:
    void    init();

    QJsonValue                  _raw_data;
    nd::storage*                _storage;
    QMap<QString, QJsonObject>  _objectsMap;
    QMap<QString, QJsonObject>  _relationsMap;
    QJsonValue                  _meta;
    QJsonValue                  _config;
    QJsonValue                  _objects;
    QJsonValue                  _relations;
    QJsonValue                  _storages;
    
};

}

#endif // APP_H
