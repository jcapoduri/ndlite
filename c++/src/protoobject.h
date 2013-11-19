#ifndef PROTO_H
#define PROTO_H
#include "ndlite_global.h"
#include <QObject>
#include <QSignalMapper>
#include <QDynamicPropertyChangeEvent>
#include <QJsonObject>
#include <QJsonDocument>
#include <functional>
#include <QVariant>

namespace nd {

class NDLITESHARED_EXPORT protoObject;

typedef std::function< void(protoObject * self, const QString & property) > proto_function;
typedef std::function< void(protoObject * self, const QString & property, const QVariant & value) > proto_function_set;


class NDLITESHARED_EXPORT protoObject : public QObject {

    Q_OBJECT

    public:

        protoObject(QObject* parent);
        protoObject(const protoObject & other);
        protoObject();

        // bind an object to a property
        void        bind(const QString & propertyName, QObject* obj );

        // bind a function to a property
        void        bind(const QString & propertyName, proto_function fun);

        // bind a custom function upon obj modification
        void        bind(const QString & propertyName, QObject * obj, proto_function_set fun);

        //
        QJsonObject toJSON();
        bool        set(const char * attr, const QVariant & value) { return this->setProperty(attr, value); }
        QVariant    get(const char * attr) { return this->property(attr);  }

        //
        void        fromJSON(QJsonObject & obj);

        bool        hasOwnProperty(const QString & property);

        bool        setProperty(const char *name, protoObject * value);
        bool        setProperty(const char *name, protoObject & value);
        bool        setProperty(const char *name, const QList<QSharedPointer<protoObject> > * value);
        bool        setProperty(const char *name, const QList<QSharedPointer<protoObject> > & value);
        bool        setProperty(const char *name, const QVariant &value);

    signals:
        void        propertyChange(QString & property, QVariant &value);

    protected slots:
        void        propertyUpdated(QString propertyName);

    protected:
        static QJsonValue   toValue();
        bool                eventFilter(QObject *sender, QEvent *ev);
        QSignalMapper*      mapper;
};

}

Q_DECLARE_METATYPE(nd::protoObject)
Q_DECLARE_METATYPE(nd::protoObject*)
Q_DECLARE_METATYPE(QList < nd::protoObject* >)
#endif // PROTO_H
