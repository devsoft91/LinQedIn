/****************************************************************************
** Meta object code from reading C++ file 'viewgestioneutenti.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LinQuedin/viewgestioneutenti.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewgestioneutenti.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ViewGestioneUtenti_t {
    QByteArrayData data[8];
    char stringdata[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewGestioneUtenti_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewGestioneUtenti_t qt_meta_stringdata_ViewGestioneUtenti = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 18),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 11),
QT_MOC_LITERAL(4, 51, 13),
QT_MOC_LITERAL(5, 65, 13),
QT_MOC_LITERAL(6, 79, 13),
QT_MOC_LITERAL(7, 93, 11)
    },
    "ViewGestioneUtenti\0enableSaveInstance\0"
    "\0sendMessage\0checkEmptyAdd\0checkEmptyDel\0"
    "checkEmptyMod\0catchSaveOn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewGestioneUtenti[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   48,    2, 0x0a /* Public */,
       5,    0,   49,    2, 0x0a /* Public */,
       6,    0,   50,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ViewGestioneUtenti::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewGestioneUtenti *_t = static_cast<ViewGestioneUtenti *>(_o);
        switch (_id) {
        case 0: _t->enableSaveInstance(); break;
        case 1: _t->sendMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->checkEmptyAdd(); break;
        case 3: _t->checkEmptyDel(); break;
        case 4: _t->checkEmptyMod(); break;
        case 5: _t->catchSaveOn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ViewGestioneUtenti::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewGestioneUtenti::enableSaveInstance)) {
                *result = 0;
            }
        }
        {
            typedef void (ViewGestioneUtenti::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewGestioneUtenti::sendMessage)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ViewGestioneUtenti::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ViewGestioneUtenti.data,
      qt_meta_data_ViewGestioneUtenti,  qt_static_metacall, 0, 0}
};


const QMetaObject *ViewGestioneUtenti::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewGestioneUtenti::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewGestioneUtenti.stringdata))
        return static_cast<void*>(const_cast< ViewGestioneUtenti*>(this));
    return QWidget::qt_metacast(_clname);
}

int ViewGestioneUtenti::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ViewGestioneUtenti::enableSaveInstance()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ViewGestioneUtenti::sendMessage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
