#ifndef MODEL_H
#define MODEL_H
#include "ndlite_global.h"
#include <QVariant>
#include <QObject>
#include <QSignalMapper>
#include <QDynamicPropertyChangeEvent>
#include <QJsonObject>
#include <QJsonDocument>
#include <functional>
#include "protoobject.h"
#include "modeldefinition.h"
#include "modelexception.h"

namespace nd {
    class NDLITESHARED_EXPORT model : public protoObject
    {
        Q_OBJECT
    public:
        explicit model(modelDefinition * def, QJsonObject attributes = QJsonObject(), QObject *parent = 0);

        bool    fetch();
        bool    save();
        bool    loadModel(QJsonObject attributes);
        bool    hasAttribute(const QString & attr);

        // helpers        
        int     id(){ return this->property("id").toInt(); }
        bool    id(int value) { return this->setProperty("id", value); }
        QString name(){ return this->objectName(); }
        QJsonObject toJSON();

    signals:

    public slots:

    private:

        modelDefinition*    definition;
    };
}
#endif // MODEL_H
