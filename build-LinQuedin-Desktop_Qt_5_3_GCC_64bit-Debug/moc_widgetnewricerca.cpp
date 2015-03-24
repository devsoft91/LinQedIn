/****************************************************************************
** Meta object code from reading C++ file 'widgetnewricerca.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LinQuedin/widgetnewricerca.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetnewricerca.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WidgetNewRicerca_t {
    QByteArrayData data[6];
    char stringdata[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetNewRicerca_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetNewRicerca_t qt_meta_stringdata_WidgetNewRicerca = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 18),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 14),
QT_MOC_LITERAL(4, 52, 16),
QT_MOC_LITERAL(5, 69, 13)
    },
    "WidgetNewRicerca\0signalFocusRicerca\0"
    "\0launchResearch\0checkEmptyFields\0"
    "warningDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetNewRicerca[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WidgetNewRicerca::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetNewRicerca *_t = static_cast<WidgetNewRicerca *>(_o);
        switch (_id) {
        case 0: _t->signalFocusRicerca(); break;
        case 1: _t->launchResearch(); break;
        case 2: _t->checkEmptyFields(); break;
        case 3: _t->warningDialog(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WidgetNewRicerca::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WidgetNewRicerca::signalFocusRicerca)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject WidgetNewRicerca::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetNewRicerca.data,
      qt_meta_data_WidgetNewRicerca,  qt_static_metacall, 0, 0}
};


const QMetaObject *WidgetNewRicerca::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetNewRicerca::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetNewRicerca.stringdata))
        return static_cast<void*>(const_cast< WidgetNewRicerca*>(this));
    return QWidget::qt_metacast(_clname);
}

int WidgetNewRicerca::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void WidgetNewRicerca::signalFocusRicerca()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
