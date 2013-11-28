/****************************************************************************
** Meta object code from reading C++ file 'apistorage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/storageEngines/apistorage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apistorage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_nd__ajax_t {
    QByteArrayData data[9];
    char stringdata[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_nd__ajax_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_nd__ajax_t qt_meta_stringdata_nd__ajax = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 12),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 14),
QT_MOC_LITERAL(4, 38, 5),
QT_MOC_LITERAL(5, 44, 10),
QT_MOC_LITERAL(6, 55, 8),
QT_MOC_LITERAL(7, 64, 3),
QT_MOC_LITERAL(8, 68, 3)
    },
    "nd::ajax\0requestStart\0\0QNetworkReply*\0"
    "reply\0requestEnd\0progress\0prg\0tot\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nd__ajax[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x05,
       5,    1,   32,    2, 0x05,
       6,    2,   35,    2, 0x05,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    7,    8,

       0        // eod
};

void nd::ajax::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ajax *_t = static_cast<ajax *>(_o);
        switch (_id) {
        case 0: _t->requestStart((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->requestEnd((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->progress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ajax::*_t)(QNetworkReply * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ajax::requestStart)) {
                *result = 0;
            }
        }
        {
            typedef void (ajax::*_t)(QNetworkReply * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ajax::requestEnd)) {
                *result = 1;
            }
        }
        {
            typedef void (ajax::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ajax::progress)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject nd::ajax::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_nd__ajax.data,
      qt_meta_data_nd__ajax,  qt_static_metacall, 0, 0}
};


const QMetaObject *nd::ajax::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nd::ajax::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_nd__ajax.stringdata))
        return static_cast<void*>(const_cast< ajax*>(this));
    return QObject::qt_metacast(_clname);
}

int nd::ajax::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void nd::ajax::requestStart(QNetworkReply * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void nd::ajax::requestEnd(QNetworkReply * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void nd::ajax::progress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_nd__apiStorage_t {
    QByteArrayData data[1];
    char stringdata[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_nd__apiStorage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_nd__apiStorage_t qt_meta_stringdata_nd__apiStorage = {
    {
QT_MOC_LITERAL(0, 0, 14)
    },
    "nd::apiStorage\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nd__apiStorage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void nd::apiStorage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject nd::apiStorage::staticMetaObject = {
    { &storage::staticMetaObject, qt_meta_stringdata_nd__apiStorage.data,
      qt_meta_data_nd__apiStorage,  qt_static_metacall, 0, 0}
};


const QMetaObject *nd::apiStorage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nd::apiStorage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_nd__apiStorage.stringdata))
        return static_cast<void*>(const_cast< apiStorage*>(this));
    return storage::qt_metacast(_clname);
}

int nd::apiStorage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = storage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
