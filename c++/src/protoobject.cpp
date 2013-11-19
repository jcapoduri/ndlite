#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QTextEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDateTimeEdit>
#include <QJsonArray>

#include "protoobject.h"

using namespace nd;

protoObject::protoObject(QObject *parent) :
    QObject(parent)
{
    installEventFilter(this);
    mapper = new QSignalMapper(this);
    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(propertyUpdated(QString)));
}


protoObject::protoObject(const protoObject &other)
{
    installEventFilter(this);
    mapper = new QSignalMapper(this);
    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(propertyUpdated(QString)));
    setParent(other.parent());
}

protoObject::protoObject() : QObject(0)
{
    installEventFilter(this);
    mapper = new QSignalMapper(this);
    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(propertyUpdated(QString)));
}

void protoObject::bind(const QString &propertyName, QObject *obj) {
    QWidget* widget;

    // cast to QLabel
    widget = qobject_cast<QLabel*>(obj);
    if (widget) {
        QLabel* edit = qobject_cast<QLabel*>(obj);

        mapper->setMapping(edit, propertyName);

        return;
    };

    // cast to QLineEdit
    widget = qobject_cast<QLineEdit*>(obj);
    if (widget) {        
        QLineEdit* edit = qobject_cast<QLineEdit*>(obj);

        mapper->setMapping(edit, propertyName);

        connect(edit, &QLineEdit::textChanged, [=](const QString & value){
            QVariant data = value;
            this->setProperty(propertyName.toStdString().c_str(), data);
        });

        return;
    };

    // cast to QComboBox
    widget = qobject_cast<QComboBox*>(obj);
    if (widget) {
        QComboBox* edit = qobject_cast<QComboBox*>(obj);

        mapper->setMapping(edit, propertyName);

        connect(edit,  static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), [=](const QString & value){
            QVariant data = value;
            this->setProperty(propertyName.toStdString().c_str(), data);
        });

        return;
    };

    // cast to QRadioButton
    widget = qobject_cast<QRadioButton*>(obj);
    if (widget) {
        QRadioButton* edit = qobject_cast<QRadioButton*>(obj);

        mapper->setMapping(edit, propertyName);

        connect(edit, &QRadioButton::clicked, [=](const bool & value){
            QVariant data = value;
            this->setProperty(propertyName.toStdString().c_str(), data);
        });

        return;
    };

    // cast to QCheckBox
    widget = qobject_cast<QCheckBox*>(obj);
    if (widget) {
        QCheckBox* edit = qobject_cast<QCheckBox*>(obj);

        mapper->setMapping(edit, propertyName);

        connect(edit, &QCheckBox::clicked, [=](const bool & value){
            QVariant data = value;
            this->setProperty(propertyName.toStdString().c_str(), data);
        });

        return;
    };

    // cast to QPlainTextEdit <- TEST
    widget = qobject_cast<QPlainTextEdit*>(obj);
    if (widget) {
        QPlainTextEdit* edit = qobject_cast<QPlainTextEdit*>(obj);

        mapper->setMapping(edit, propertyName);

        connect(edit, &QPlainTextEdit::textChanged, [=](){
            //qDebug() << sender();
            QVariant data;// = value;
            this->setProperty(propertyName.toStdString().c_str(), data);
        });

        return;
    };

    // cast to QSpinBox
    widget = qobject_cast<QSpinBox*>(obj);
    if (widget) {
        QSpinBox* edit = qobject_cast<QSpinBox*>(obj);

        mapper->setMapping(edit, propertyName);

        connect(edit, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](int value){
            QVariant data = value;
            this->setProperty(propertyName.toStdString().c_str(), data);
        });

        return;
    };

    // cast to QDoubleSpinBox
    widget = qobject_cast<QDoubleSpinBox*>(obj);
    if (widget) {
        QDoubleSpinBox* edit = qobject_cast<QDoubleSpinBox*>(obj);

        mapper->setMapping(edit, propertyName);

        connect(edit, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), [=](double value){
            QVariant data = value;
            this->setProperty(propertyName.toStdString().c_str(), data);
        });

        return;
    };

    // cast to QDateTimeEdit
    widget = qobject_cast<QDateTimeEdit*>(obj);
    if (widget) {
        QDateTimeEdit* edit = qobject_cast<QDateTimeEdit*>(obj);

        mapper->setMapping(edit, propertyName);

        connect(edit, &QDateTimeEdit::dateTimeChanged, [=](const QDateTime & value){
            QVariant data = value;
            this->setProperty(propertyName.toStdString().c_str(), data);
        });

        return;
    };

}

void protoObject::bind(const QString &propertyName, proto_function fun) {
    connect(this, &protoObject::propertyChange, [=](QString value){
        if (propertyName == value) fun(this, propertyName);
    });
}


void protoObject::bind(const QString &propertyName, QObject *obj, proto_function_set fun) {
    QWidget* widget;

    // cast to QLineEdit
    widget = qobject_cast<QLineEdit*>(obj);
    if (widget) {
        QLineEdit* edit = qobject_cast<QLineEdit*>(obj);
        mapper->setMapping(edit, propertyName);
        connect(edit, &QLineEdit::textChanged, [=](const QString & value){
            QString data = value;
            fun(this, propertyName, data);
        });
        return;
    };

    // cast to QComboBox
    widget = qobject_cast<QComboBox*>(obj);
    if (widget) {
        QComboBox* edit = qobject_cast<QComboBox*>(obj);
        mapper->setMapping(edit, propertyName);
        connect(edit, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), [=](const QString & value){
            QString data = value;
            fun(this, propertyName, data);
        });
        return;
    };

    // cast to QRadioButton
    widget = qobject_cast<QRadioButton*>(obj);
    if (widget) {
        QRadioButton* edit = qobject_cast<QRadioButton*>(obj);
        mapper->setMapping(edit, propertyName);
        connect(edit, &QRadioButton::clicked, [=](const bool & value){
            QVariant data = value;
            fun(this, propertyName, data);
        });
        return;
    };

    // cast to QCheckBox
    widget = qobject_cast<QCheckBox*>(obj);
    if (widget) {
        QCheckBox* edit = qobject_cast<QCheckBox*>(obj);
        mapper->setMapping(edit, propertyName);
        connect(edit, &QCheckBox::clicked, [=](const bool & value){
            QVariant data = value;
            fun(this, propertyName, data);
        });
        return;
    };

    // cast to QPlainTextEdit
    widget = qobject_cast<QPlainTextEdit*>(obj);
    if (widget) {
        QPlainTextEdit* edit = qobject_cast<QPlainTextEdit*>(obj);
        mapper->setMapping(edit, propertyName);
        connect(edit, &QPlainTextEdit::textChanged, [=](){
            QVariant data;// = value;
            fun(this, propertyName, data);
        });
        return;
    };

    // cast to QSpinBox
    widget = qobject_cast<QSpinBox*>(obj);
    if (widget) {
        QSpinBox* edit = qobject_cast<QSpinBox*>(obj);
        mapper->setMapping(edit, propertyName);
        connect(edit, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](int value){
            QVariant data = value;
            fun(this, propertyName, data);
        });
        return;
    };

    // cast to QDoubleSpinBox
    widget = qobject_cast<QDoubleSpinBox*>(obj);
    if (widget) {
        QDoubleSpinBox* edit = qobject_cast<QDoubleSpinBox*>(obj);
        mapper->setMapping(edit, propertyName);
        connect(edit, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), [=](double value){
            QVariant data = value;
            fun(this, propertyName, data);
        });
        return;
    };

    // cast to QDateTimeEdit
    widget = qobject_cast<QDateTimeEdit*>(obj);
    if (widget) {
        QDateTimeEdit* edit = qobject_cast<QDateTimeEdit*>(obj);
        mapper->setMapping(edit, propertyName);
        connect(edit, &QDateTimeEdit::dateTimeChanged, [=](const QDateTime & value){
            QVariant data = value;
            fun(this, propertyName, data);
        });
        return;
    };
}

QJsonObject protoObject::toJSON() {
    //TODO
    QJsonObject obj;
    QList<QByteArray> properties = this->dynamicPropertyNames();
    QString property;
    protoObject* tmp_val;
    int length = properties.length();


    for(int i = 0; i < length; i++) {
        property = QString(properties.at(i));
        QVariant value = this->property(property.toLatin1());
        if (value.canConvert<QSharedPointer<protoObject> >()) {
            //tmp_val = dynamic_cast<protoObject*>(value.value());
            tmp_val = value.value<QSharedPointer<protoObject> >().data();
            obj.insert(property, tmp_val->toJSON());
            continue;
        };
        if (value.canConvert< QList<QSharedPointer<protoObject> > >()) {
            //qDebug() << "converted to list" << property;
            QList<QSharedPointer<protoObject> > list = value.value< QList<QSharedPointer<protoObject> > >();
            //qDebug() << list;
            QJsonArray tmp_arr;
            int length = list.length();
            for(int j = 0; j < length; j++) {
                tmp_val = list.at(j).data();
                tmp_arr.append(tmp_val->toJSON());
            };
            obj.insert(property, tmp_arr);
            continue;
        };
        obj.insert(property, QJsonValue(this->property(property.toLatin1()).toString()));
    };
    return obj;
}

void protoObject::fromJSON(QJsonObject &obj) {
    //TODO: internal id check
    //qDebug() << obj;
    QMap<QString, QMap<int, protoObject* >* > bufferMap;
    QMap<int, protoObject* >* tmp_bufferMap;

    int         length = obj.size();
    int         i;
    protoObject*      tmp_obj;
    QStringList keys = obj.keys();
    QJsonValue  value;
    QJsonObject json_obj;
    QJsonObject json_info;

    for (i = 0; i < length; i++) {
        value = obj.value(keys.at(i));
        if (value.isArray()) {            
            QJsonArray tmp_arr = value.toArray();
            QList< QSharedPointer<protoObject> > list;
            int length = tmp_arr.count(), j;
            for (j = 0; j < length; j++) {
                tmp_obj = new protoObject(this);
                value = tmp_arr.at(j);
                if (value.isObject()) {                    
                    json_obj = value.toObject();
                    tmp_obj->fromJSON(json_obj);
                };
                list.append(QSharedPointer<protoObject >(tmp_obj));
            };
            qDebug() << list;
            this->setProperty(keys.at(i).toLatin1(), QVariant::fromValue(list));
        };
        if (value.isObject()) {
            tmp_obj = new protoObject(this);
            json_obj = value.toObject();
            tmp_obj->fromJSON(json_obj);
            QVariant variant = QVariant::fromValue(QSharedPointer<protoObject>(tmp_obj));
            this->setProperty(keys.at(i).toLatin1(), variant);
        };
        if (value.isString()) this->setProperty(keys.at(i).toLatin1(), value.toString());
        if (value.isDouble()) this->setProperty(keys.at(i).toLatin1(), value.toDouble());
        if (value.isBool()) this->setProperty(keys.at(i).toLatin1(), value.toBool());
    };
}

bool protoObject::hasOwnProperty(const QString &property)
{
    return this->dynamicPropertyNames().contains(property.toLatin1());
}

bool nd::protoObject::setProperty(const char *name, const QVariant &value)
{
    return QObject::setProperty(name, value);
}

bool nd::protoObject::setProperty(const char *name, const QList<QSharedPointer<nd::protoObject> > &value)
{
    QVariant var = QVariant::fromValue(value);
    return setProperty(name, var);
}

bool nd::protoObject::setProperty(const char *name, const QList<QSharedPointer<nd::protoObject> > *value)
{
    QVariant var = QVariant::fromValue(*value);
    return setProperty(name, var);
}

bool nd::protoObject::setProperty(const char *name, nd::protoObject & value)
{
    QVariant var = QVariant::fromValue(QSharedPointer<nd::protoObject>(&value));
    return setProperty(name, var);
}

bool nd::protoObject::setProperty(const char *name, nd::protoObject *value)
{
    QVariant var = QVariant::fromValue(QSharedPointer<nd::protoObject>(value));
    return setProperty(name, var);
}

void protoObject::propertyUpdated(QString propertyName){
    QObject *receiver = mapper->mapping(propertyName);
    QWidget *widget;

    if (receiver) return; //if not binding, just leave

    widget = qobject_cast<QLabel*>(receiver);
    if (widget) {
        QLabel* edit = qobject_cast<QLabel*>(receiver);
        QString value = this->property(propertyName.toLatin1()).toString();
        edit->blockSignals(true);
        edit->setText(edit->text().arg(value));
        edit->blockSignals(false);
    };

    widget = qobject_cast<QLineEdit*>(receiver);
    if (widget) {
        QLineEdit* edit = qobject_cast<QLineEdit*>(receiver);
        QString value = this->property(propertyName.toLatin1()).toString();
        edit->blockSignals(true);
        edit->setText(value);
        edit->blockSignals(false);
    };

    widget = qobject_cast<QComboBox*>(receiver);
    if (widget) {
        QComboBox* edit = qobject_cast<QComboBox*>(receiver);
        edit->blockSignals(true);
        edit->setCurrentIndex(edit->findData(this->property(propertyName.toLatin1()), Qt::UserRole));
        edit->blockSignals(false);
    };

    widget = qobject_cast<QRadioButton*>(receiver);
    if (widget) {
        QRadioButton* edit = qobject_cast<QRadioButton*>(receiver);
        bool value = this->property(propertyName.toLatin1()).toBool();
        edit->blockSignals(true);
        edit->setChecked(value);
        edit->blockSignals(false);
    };

    widget = qobject_cast<QCheckBox*>(receiver);
    if (widget) {
        QCheckBox* edit = qobject_cast<QCheckBox*>(receiver);
        bool value = this->property(propertyName.toLatin1()).toBool();
        edit->blockSignals(true);
        edit->setChecked(value);
        edit->blockSignals(false);
    };

    widget = qobject_cast<QPlainTextEdit*>(receiver);
    if (widget) {
        QPlainTextEdit* edit = qobject_cast<QPlainTextEdit*>(receiver);
        QString value = this->property(propertyName.toLatin1()).toString();
        edit->blockSignals(true);
        edit->setPlainText(value);
        edit->blockSignals(false);
    };

    widget = qobject_cast<QSpinBox*>(receiver);
    if (widget) {
        QSpinBox* edit = qobject_cast<QSpinBox*>(receiver);
        int value = this->property(propertyName.toLatin1()).toInt();
        edit->blockSignals(true);
        edit->setValue(value);
        edit->blockSignals(false);
    };

    widget = qobject_cast<QDoubleSpinBox*>(receiver);
    if (widget) {
        QDoubleSpinBox* edit = qobject_cast<QDoubleSpinBox*>(receiver);
        double value = this->property(propertyName.toLatin1()).toDouble();
        edit->blockSignals(true);
        edit->setValue(value);
        edit->blockSignals(false);
    };

    widget = qobject_cast<QDateTimeEdit*>(receiver);
    if (widget) {
        QDateTimeEdit* edit = qobject_cast<QDateTimeEdit*>(receiver);
        QDateTime value = this->property(propertyName.toLatin1()).toDateTime();
        edit->blockSignals(true);
        edit->setDateTime(value);
        edit->blockSignals(false);
    };
}

bool protoObject::eventFilter(QObject *sender, QEvent *ev){
    if (ev->type() == QEvent::DynamicPropertyChange){
        QDynamicPropertyChangeEvent *propEvent = static_cast<QDynamicPropertyChangeEvent*>(ev);
        QVariant value = this->property(propEvent->propertyName());
        if (value.isValid()) {
            QString propertyName = propEvent->propertyName();
            this->propertyUpdated(propertyName);
            //qDebug() << "before property change";
            emit propertyChange(propertyName, value);
        };
    }
    return QObject::eventFilter(sender, ev);
}
