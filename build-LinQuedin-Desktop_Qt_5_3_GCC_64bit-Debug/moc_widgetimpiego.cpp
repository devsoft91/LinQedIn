/****************************************************************************
** Meta object code from reading C++ file 'widgetimpiego.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LinQuedin/widgetimpiego.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetimpiego.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WidgetImpiego_t {
    QByteArrayData data[10];
    char stringdata[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetImpiego_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetImpiego_t qt_meta_stringdata_WidgetImpiego = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 14),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 14),
QT_MOC_LITERAL(4, 45, 14),
QT_MOC_LITERAL(5, 60, 12),
QT_MOC_LITERAL(6, 73, 13),
QT_MOC_LITERAL(7, 87, 12),
QT_MOC_LITERAL(8, 100, 11),
QT_MOC_LITERAL(9, 112, 8)
    },
    "WidgetImpiego\0signalRemoveId\0\0"
    "WidgetImpiego*\0signalUpdateId\0"
    "enableUpdate\0disableUpdate\0sendRemoveId\0"
    "updateState\0backData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetImpiego[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    6,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   70,    2, 0x0a /* Public */,
       5,    1,   73,    2, 0x0a /* Public */,
       6,    0,   76,    2, 0x0a /* Public */,
       7,    0,   77,    2, 0x0a /* Public */,
       8,    0,   78,    2, 0x0a /* Public */,
       9,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QDate, QMetaType::QDate,    2,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WidgetImpiego::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetImpiego *_t = static_cast<WidgetImpiego *>(_o);
        switch (_id) {
        case 0: _t->signalRemoveId((*reinterpret_cast< WidgetImpiego*(*)>(_a[1]))); break;
        case 1: _t->signalUpdateId((*reinterpret_cast< WidgetImpiego*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QDate(*)>(_a[5])),(*reinterpret_cast< const QDate(*)>(_a[6]))); break;
        case 2: _t->enableUpdate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->enableUpdate((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 4: _t->disableUpdate(); break;
        case 5: _t->sendRemoveId(); break;
        case 6: _t->updateState(); break;
        case 7: _t->backData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WidgetImpiego* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WidgetImpiego* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WidgetImpiego::*_t)(WidgetImpiego * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WidgetImpiego::signalRemoveId)) {
                *result = 0;
            }
        }
        {
            typedef void (WidgetImpiego::*_t)(WidgetImpiego * , const QString & , const QString & , const QString & , const QDate & , const QDate & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WidgetImpiego::signalUpdateId)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject WidgetImpiego::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetImpiego.data,
      qt_meta_data_WidgetImpiego,  qt_static_metacall, 0, 0}
};


const QMetaObject *WidgetImpiego::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetImpiego::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetImpiego.stringdata))
        return static_cast<void*>(const_cast< WidgetImpiego*>(this));
    return QWidget::qt_metacast(_clname);
}

int WidgetImpiego::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void WidgetImpiego::signalRemoveId(WidgetImpiego * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WidgetImpiego::signalUpdateId(WidgetImpiego * _t1, const QString & _t2, const QString & _t3, const QString & _t4, const QDate & _t5, const QDate & _t6)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
