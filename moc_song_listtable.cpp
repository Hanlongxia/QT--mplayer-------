/****************************************************************************
** Meta object code from reading C++ file 'song_listtable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "song_listtable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'song_listtable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Song_listTable_t {
    QByteArrayData data[6];
    char stringdata[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Song_listTable_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Song_listTable_t qt_meta_stringdata_Song_listTable = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Song_listTable"
QT_MOC_LITERAL(1, 15, 52), // "Song_Listtable_01_Receive_The..."
QT_MOC_LITERAL(2, 68, 0), // ""
QT_MOC_LITERAL(3, 69, 5), // "char*"
QT_MOC_LITERAL(4, 75, 52), // "Song_Listtable_02_Receive_The..."
QT_MOC_LITERAL(5, 128, 1) // "a"

    },
    "Song_listTable\0"
    "Song_Listtable_01_Receive_The_widget_Response_Signal\0"
    "\0char*\0Song_Listtable_02_Receive_The_widget_Response_Signal\0"
    "a"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Song_listTable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    1,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void Song_listTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Song_listTable *_t = static_cast<Song_listTable *>(_o);
        switch (_id) {
        case 0: _t->Song_Listtable_01_Receive_The_widget_Response_Signal((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 1: _t->Song_Listtable_02_Receive_The_widget_Response_Signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Song_listTable::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Song_listTable.data,
      qt_meta_data_Song_listTable,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Song_listTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Song_listTable::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Song_listTable.stringdata))
        return static_cast<void*>(const_cast< Song_listTable*>(this));
    return QWidget::qt_metacast(_clname);
}

int Song_listTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
