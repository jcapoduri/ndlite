#ifndef MODELDEFINITION_H
#define MODELDEFINITION_H

#include <QObject>
#include "ndlite_global.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QMap>
#include <QStringList>
#include <functional>

namespace nd {

    class NDLITESHARED_EXPORT app;

    class NDLITESHARED_EXPORT model;

    class NDLITESHARED_EXPORT modelDefinition : public QObject
    {
        Q_OBJECT
    public:
        enum modelFieldType { string, number, decimal, object, array, date, datetime, time, boolean, enumeration};
        struct modelFieldDefinition {
            QString         name;
            modelFieldType  type;
            QString         objectName;
            QStringList     enum_values;
        };
        explicit    modelDefinition(const QString & modelname, const QJsonObject & definition, app * appllication, QObject *parent = 0);
        bool        isValid() { return _isValid; }
        QString     name() { return modelName; }
        QStringList fieldNames(){ return fields.keys(); }
        modelFieldDefinition field(const QString & key) { return fields.value(key); }
        app*        application() { return _application; }
        model*      create(QJsonObject obj = QJsonObject());

    signals:

    public slots:

    private:
        modelFieldDefinition    createFieldDefinition(QJsonObject & def);
        QString                 modelName;
        bool                    nd_fields;
        bool                    _isValid;
        QMap<QString, modelFieldDefinition>    fields;
        app*                    _application;

    };
}
#endif // MODELDEFINITION_H
