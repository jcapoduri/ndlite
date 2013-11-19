#include <QVariant>
#include "model.h"
#include "app.h"
#include <QSharedPointer>
#include <QDebug>

nd::model::model(modelDefinition *def, QJsonObject attributes, QObject *parent) :
    protoObject(parent)
{
    definition = def;
    QStringList keys = definition->fieldNames();
    modelDefinition::modelFieldDefinition field;
    setObjectName(def->name());

    for (int i = 0; i < keys.count(); i++) {        
        field = definition->field(keys.at(i));
        qDebug() << keys.at(i) << field.name;
        if (field.type == modelDefinition::object) {
            QVariant variant;
            variant = QVariant::fromValue(QSharedPointer<protoObject>());
            this->setProperty(field.name.toLatin1(), variant);
            continue;
        };

        if (field.type == modelDefinition::array) {
            QList< QSharedPointer<protoObject> > list;
            QVariant variant = QVariant::fromValue(list);
            this->setProperty(field.name.toLatin1(), variant);
            continue;
        };

        this->setProperty(field.name.toLatin1(), QString(""));
    };

    if (!attributes.isEmpty()) {
        // load model
    };
}

bool nd::model::fetch()
{
    nd::app* app = this->definition->application();
    QJsonValue result = app->api()->get(name(), id());
    qDebug() << result;
    qDebug() << result.toObject();
    return this->loadModel(result.toObject());
}

bool nd::model::save()
{
    nd::app* app = this->definition->application();
    qDebug() << "model json: " << toJSON();
    return app->api()->save(name(), toJSON());
}

bool nd::model::loadModel(QJsonObject attributes)
{
    if (attributes.isEmpty()) return true;    
    QStringList keys = attributes.keys();
    QString key;
    foreach (key, keys) {
        qDebug() << key;
        if (hasAttribute(key)){
            QVariant value;
            modelDefinition::modelFieldDefinition field = definition->field(key);
            if (field.type == modelDefinition::object || field.type == modelDefinition::array) {
                if (field.type == modelDefinition::object)  {
                    QJsonObject field_def = attributes.value(key).toObject();
                    value = QVariant::fromValue(QSharedPointer<protoObject>(definition->application()->model(field.objectName)->create(field_def)));
                } else {
                    QJsonArray field_list = attributes.value(key).toArray();
                    QList<QSharedPointer<protoObject> > list;
                    int i = 0, len = field_list.count();
                    for (; i < len; i++) {
                        qDebug() << i;
                        QJsonObject field_def = field_list.at(i).toObject();
                        qDebug() << field.name << field.objectName;
                        list.append(QSharedPointer<protoObject>(definition->application()->model(field.objectName)->create(field_def)));
                    }
                    value = QVariant::fromValue(list);
                };
            } else {
                value = QVariant(attributes.value(key).toVariant());
            };
            this->setProperty(key.toLatin1(), value);
        };
    }
    return true;
}

bool nd::model::hasAttribute(const QString &attr)
{
    return this->dynamicPropertyNames().contains(attr.toLatin1());
}

QJsonObject nd::model::toJSON()
{
    QJsonObject obj;
    obj = protoObject::toJSON();
    obj.remove("ctime");
    obj.remove("dtime");
    obj.remove("mtime");
    obj.remove("deleted");
    obj.remove("usrid");
    return obj;
}
