#ifndef APP_H
#define APP_H

#include "ndlite_global.h"
#include <QObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>
#include <QString>
#include "api.h"
#include "solution.h"
#include "model.h"

namespace nd {

/*
app - application
manage models and object and data for the application
*/
class NDLITESHARED_EXPORT app : public QObject
{
    Q_OBJECT
public:
    enum define_option {object, relation, storage};

    app(QJsonValue & initdata, solution *sol,  QObject *parent = 0);
    ~app();

    void             loadData(const QJsonValue & value);
    void             define(define_option type, const QString & objname, QJsonObject initdata = QJsonObject());
    QJsonObject      getDefinition(define_option type, const QString & objname);
    modelDefinition* getModel(const QString & name) { return models.value(name); }

    nd::api*         api();

    static modelDefinition *model(const QString & name);
signals:
    
public slots:

protected:
    void                        setField(const QJsonObject & field, protoObject * obj);
    void                        addRelation(const QJsonObject & obj);
    QString                     appname;
    nd::api*                    manager;
    nd::solution*               solution;

    QJsonValue                  raw_data;
    QMap<QString, modelDefinition*> models;
    QMap<QString, QJsonObject>      objects;
    QMap<QString, QJsonObject>      storages;
    QMap<QString, QJsonObject>      relations;

private:
    static      app*    default_app;
};

}

#endif // APP_H
