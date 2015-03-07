/****************************************************************************
** Meta object code from reading C++ file 'widgetnewimpiego.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LinQuedin/widgetnewimpiego.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetnewimpiego.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WidgetNewImpiego_t {
    QByteArrayData data[6];
    char stringdata[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetNewImpiego_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetNewImpiego_t qt_meta_stringdata_WidgetNewImpiego = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 19),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 10),
QT_MOC_LITERAL(4, 49, 10),
QT_MOC_LITERAL(5, 60, 15)
    },
    "WidgetNewImpiego\0callFetchNewImpiego\0"
    "\0QLineEdit*\0QDateEdit*\0newImpiegoReady"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetNewImpiego[] = {

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
       1,    5,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 4, 0x80000000 | 4,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void WidgetNewImpiego::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetNewImpiego *_t = static_cast<WidgetNewImpiego *>(_o);
        switch (_id) {
        case 0: _t->callFetchNewImpiego((*reinterpret_cast< QLineEdit*(*)>(_a[1])),(*reinterpret_cast< QLineEdit*(*)>(_a[2])),(*reinterpret_cast< QLineEdit*(*)>(_a[3])),(*reinterpret_cast< QDateEdit*(*)>(_a[4])),(*reinterpret_cast< QDateEdit*(*)>(_a[5]))); break;
        case 1: _t->newImpiegoReady(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDateEdit* >(); break;
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WidgetNewImpiego::*_t)(QLineEdit * , QLineEdit * , QLineEdit * , QDateEdit * , QDateEdit * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WidgetNewImpiego::callFetchNewImpiego)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WidgetNewImpiego::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetNewImpiego.data,
      qt_meta_data_WidgetNewImpiego,  qt_static_metacall, 0, 0}
};


const QMetaObject *WidgetNewImpiego::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetNewImpiego::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetNewImpiego.stringdata))
        return static_cast<void*>(const_cast< WidgetNewImpiego*>(this));
    return QWidget::qt_metacast(_clname);
}

int WidgetNewImpiego::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void WidgetNewImpiego::callFetchNewImpiego(QLineEdit * _t1, QLineEdit * _t2, QLineEdit * _t3, QDateEdit * _t4, QDateEdit * _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
