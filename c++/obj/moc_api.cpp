/****************************************************************************
** Meta object code from reading C++ file 'api.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/api.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'api.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_nd__api_t {
    QByteArrayData data[10];
    char stringdata[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_nd__api_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_nd__api_t qt_meta_stringdata_nd__api = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 4),
QT_MOC_LITERAL(2, 13, 0),
QT_MOC_LITERAL(3, 14, 12),
QT_MOC_LITERAL(4, 27, 3),
QT_MOC_LITERAL(5, 31, 7),
QT_MOC_LITERAL(6, 39, 3),
QT_MOC_LITERAL(7, 43, 2),
QT_MOC_LITERAL(8, 46, 5),
QT_MOC_LITERAL(9, 52, 5)
    },
    "nd::api\0save\0\0protoObject*\0obj\0objname\0"
    "get\0id\0route\0erase\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nd__api[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a,
       1,    2,   62,    2, 0x0a,
       6,    2,   67,    2, 0x0a,
       6,    1,   72,    2, 0x2a,
       6,    1,   75,    2, 0x0a,
       6,    2,   78,    2, 0x0a,
       9,    1,   83,    2, 0x0a,
       9,    2,   86,    2, 0x0a,
       9,    2,   91,    2, 0x0a,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 3,    4,
    QMetaType::Bool, QMetaType::QString, QMetaType::QJsonObject,    5,    4,
    QMetaType::QJsonValue, QMetaType::QString, QMetaType::Int,    5,    7,
    QMetaType::QJsonValue, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::QJsonValue, QMetaType::QString, QMetaType::QString,    5,    8,
    QMetaType::Bool, 0x80000000 | 3,    4,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,    5,    7,
    QMetaType::Bool, QMetaType::QString, QMetaType::QJsonObject,    5,    4,

       0        // eod
};

void nd::api::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        api *_t = static_cast<api *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->save((*reinterpret_cast< protoObject*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->save((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { QJsonValue _r = _t->get((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QJsonValue*>(_a[0]) = _r; }  break;
        case 3: { QJsonValue _r = _t->get((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonValue*>(_a[0]) = _r; }  break;
        case 4: _t->get((*reinterpret_cast< protoObject*(*)>(_a[1]))); break;
        case 5: { QJsonValue _r = _t->get((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QJsonValue*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->erase((*reinterpret_cast< protoObject*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->erase((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->erase((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject nd::api::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_nd__api.data,
      qt_meta_data_nd__api,  qt_static_metacall, 0, 0}
};


const QMetaObject *nd::api::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nd::api::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_nd__api.stringdata))
        return static_cast<void*>(const_cast< api*>(this));
    return QObject::qt_metacast(_clname);
}

int nd::api::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
