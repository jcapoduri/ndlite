#include "modeldefinition.h"
#include "app.h"
#include "model.h"
#include <QDebug>

nd::modelDefinition::modelDefinition(const QString &modelname, const QJsonObject &definition, app *appllication, QObject *parent) :
    QObject(parent),
    _isValid(false)
{
    this->_application = appllication;
    if (this->parent() == 0) setParent(appllication);
    this->modelName = modelname;
    QJsonArray fields_array = definition.value("fields").toArray();
    int i = 0, len = fields_array.count();
    for(; i < len; i++) {
        QJsonObject field_def = fields_array.at(i).toObject();
        fields.insert(field_def.value("name").toString(), createFieldDefinition(field_def));
    };

    if (definition.value("nd_fields").toBool()) {
        fields_array = nd::nd_fields;
        i = 0, len = fields_array.count();
        for(; i < len; i++) {
            QJsonObject field_def = fields_array.at(i).toObject();
            fields.insert(field_def.value("name").toString(), createFieldDefinition(field_def));
        };
    };

}

nd::model *nd::modelDefinition::create(QJsonObject obj)
{
    nd::model* model = new nd::model(this);
    if (!obj.isEmpty()) model->loadModel(obj);
    return model;
}

nd::modelDefinition::modelFieldDefinition nd::modelDefinition::createFieldDefinition(QJsonObject &def)
{
    modelFieldDefinition field;
    QString type = def.value("type").toString().toLower();
    QString name = def.value("name").toString();

    if (type == "object" || type == "array") {
        if (type == "object") {
            //obj->setProperty(name.toLatin1(), QVariant::fromValue((new protoObject(this))));
            field.type = object;
            field.objectName = def.value("object_name").toString();            
        } else {
            //qDebug() << "is array";
            field.type = array;
            field.objectName = def.value("relation_name").toString();
            //qDebug() << field.objectName;
            QJsonObject rel_info = this->application()->getDefinition(app::relation, field.objectName);
            //qDebug() << rel_info;
            field.objectName = rel_info.value("object_to").toString();
            //qDebug() << name << field.type << field.objectName;
        };
    } else {
        //obj->setProperty(name.toLatin1(), QVariant(field.value("default")));
        if (type == "string") field.type = string;
        if (type == "decimal") field.type = decimal;
        if (type == "number") field.type = number;
        if (type == "enum") field.type = enumeration;
        if (type == "date") field.type = date;
        if (type == "time") field.type = time;
        if (type == "datetime") field.type = datetime;
        if (type == "bool") field.type = boolean;
    };
    field.name = name;
    return field;
}
