/****************************************************************************
** Meta object code from reading C++ file 'protoobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/protoobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protoobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_nd__protoObject_t {
    QByteArrayData data[9];
    char stringdata[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_nd__protoObject_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_nd__protoObject_t qt_meta_stringdata_nd__protoObject = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 14),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 8),
QT_MOC_LITERAL(4, 41, 8),
QT_MOC_LITERAL(5, 50, 9),
QT_MOC_LITERAL(6, 60, 5),
QT_MOC_LITERAL(7, 66, 15),
QT_MOC_LITERAL(8, 82, 12)
    },
    "nd::protoObject\0propertyChange\0\0"
    "QString&\0property\0QVariant&\0value\0"
    "propertyUpdated\0propertyName\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nd__protoObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    1,   29,    2, 0x09,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void nd::protoObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        protoObject *_t = static_cast<protoObject *>(_o);
        switch (_id) {
        case 0: _t->propertyChange((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 1: _t->propertyUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (protoObject::*_t)(QString & , QVariant & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&protoObject::propertyChange)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject nd::protoObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_nd__protoObject.data,
      qt_meta_data_nd__protoObject,  qt_static_metacall, 0, 0}
};


const QMetaObject *nd::protoObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nd::protoObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_nd__protoObject.stringdata))
        return static_cast<void*>(const_cast< protoObject*>(this));
    return QObject::qt_metacast(_clname);
}

int nd::protoObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void nd::protoObject::propertyChange(QString & _t1, QVariant & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
