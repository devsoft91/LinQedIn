/****************************************************************************
** Meta object code from reading C++ file 'widgetwelcome.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LinQuedin/widgetwelcome.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetwelcome.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WidgetWelcome_t {
    QByteArrayData data[5];
    char stringdata[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetWelcome_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetWelcome_t qt_meta_stringdata_WidgetWelcome = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 9),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 10),
QT_MOC_LITERAL(4, 36, 16)
    },
    "WidgetWelcome\0callAdmin\0\0callClient\0"
    "checkStringLogin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetWelcome[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void WidgetWelcome::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetWelcome *_t = static_cast<WidgetWelcome *>(_o);
        switch (_id) {
        case 0: _t->callAdmin(); break;
        case 1: _t->callClient(); break;
        case 2: _t->checkStringLogin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WidgetWelcome::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WidgetWelcome::callAdmin)) {
                *result = 0;
            }
        }
        {
            typedef void (WidgetWelcome::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WidgetWelcome::callClient)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject WidgetWelcome::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetWelcome.data,
      qt_meta_data_WidgetWelcome,  qt_static_metacall, 0, 0}
};


const QMetaObject *WidgetWelcome::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetWelcome::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetWelcome.stringdata))
        return static_cast<void*>(const_cast< WidgetWelcome*>(this));
    return QWidget::qt_metacast(_clname);
}

int WidgetWelcome::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void WidgetWelcome::callAdmin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void WidgetWelcome::callClient()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
