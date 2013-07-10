/****************************************************************************
** Meta object code from reading C++ file 'field.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/field.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'field.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_nd__field_t {
    QByteArrayData data[12];
    char stringdata[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_nd__field_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_nd__field_t qt_meta_stringdata_nd__field = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 4),
QT_MOC_LITERAL(2, 15, 6),
QT_MOC_LITERAL(3, 22, 6),
QT_MOC_LITERAL(4, 29, 7),
QT_MOC_LITERAL(5, 37, 6),
QT_MOC_LITERAL(6, 44, 5),
QT_MOC_LITERAL(7, 50, 4),
QT_MOC_LITERAL(8, 55, 4),
QT_MOC_LITERAL(9, 60, 4),
QT_MOC_LITERAL(10, 65, 4),
QT_MOC_LITERAL(11, 70, 9)
    },
    "nd::field\0Type\0String\0Number\0Decimal\0"
    "Object\0Array\0Enum\0Bool\0Time\0Date\0"
    "Timestamp\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_nd__field[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,   10,   18,

 // enum data: key, value
       2, uint(nd::field::String),
       3, uint(nd::field::Number),
       4, uint(nd::field::Decimal),
       5, uint(nd::field::Object),
       6, uint(nd::field::Array),
       7, uint(nd::field::Enum),
       8, uint(nd::field::Bool),
       9, uint(nd::field::Time),
      10, uint(nd::field::Date),
      11, uint(nd::field::Timestamp),

       0        // eod
};

void nd::field::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject nd::field::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_nd__field.data,
      qt_meta_data_nd__field,  qt_static_metacall, 0, 0}
};


const QMetaObject *nd::field::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *nd::field::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_nd__field.stringdata))
        return static_cast<void*>(const_cast< field*>(this));
    return QObject::qt_metacast(_clname);
}

int nd::field::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
