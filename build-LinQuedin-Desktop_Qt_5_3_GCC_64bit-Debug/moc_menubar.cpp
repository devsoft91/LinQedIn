/****************************************************************************
** Meta object code from reading C++ file 'menubar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LinQuedin/menubar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menubar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MenuBar_t {
    QByteArrayData data[15];
    char stringdata[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuBar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuBar_t qt_meta_stringdata_MenuBar = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 10),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 8),
QT_MOC_LITERAL(4, 29, 17),
QT_MOC_LITERAL(5, 47, 11),
QT_MOC_LITERAL(6, 59, 15),
QT_MOC_LITERAL(7, 75, 16),
QT_MOC_LITERAL(8, 92, 10),
QT_MOC_LITERAL(9, 103, 11),
QT_MOC_LITERAL(10, 115, 11),
QT_MOC_LITERAL(11, 127, 10),
QT_MOC_LITERAL(12, 138, 11),
QT_MOC_LITERAL(13, 150, 15),
QT_MOC_LITERAL(14, 166, 14)
    },
    "MenuBar\0logoutSave\0\0exitSave\0"
    "signalCheckSaveOn\0checkSaveOn\0"
    "enableMenuLogin\0disableMenuLogin\0"
    "enableSave\0disableSave\0cancelState\0"
    "enableFind\0disableFind\0triggeredLogout\0"
    "triggeredClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    1,   82,    2, 0x06 /* Public */,
       4,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   88,    2, 0x0a /* Public */,
       6,    0,   91,    2, 0x0a /* Public */,
       7,    0,   92,    2, 0x0a /* Public */,
       8,    0,   93,    2, 0x0a /* Public */,
       9,    0,   94,    2, 0x0a /* Public */,
      10,    0,   95,    2, 0x0a /* Public */,
      11,    0,   96,    2, 0x0a /* Public */,
      12,    0,   97,    2, 0x0a /* Public */,
      13,    0,   98,    2, 0x0a /* Public */,
      14,    0,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MenuBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MenuBar *_t = static_cast<MenuBar *>(_o);
        switch (_id) {
        case 0: _t->logoutSave((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->exitSave((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->signalCheckSaveOn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->checkSaveOn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->enableMenuLogin(); break;
        case 5: _t->disableMenuLogin(); break;
        case 6: _t->enableSave(); break;
        case 7: _t->disableSave(); break;
        case 8: _t->cancelState(); break;
        case 9: _t->enableFind(); break;
        case 10: _t->disableFind(); break;
        case 11: _t->triggeredLogout(); break;
        case 12: _t->triggeredClose(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MenuBar::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuBar::logoutSave)) {
                *result = 0;
            }
        }
        {
            typedef void (MenuBar::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuBar::exitSave)) {
                *result = 1;
            }
        }
        {
            typedef void (MenuBar::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuBar::signalCheckSaveOn)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MenuBar::staticMetaObject = {
    { &QMenuBar::staticMetaObject, qt_meta_stringdata_MenuBar.data,
      qt_meta_data_MenuBar,  qt_static_metacall, 0, 0}
};


const QMetaObject *MenuBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MenuBar.stringdata))
        return static_cast<void*>(const_cast< MenuBar*>(this));
    return QMenuBar::qt_metacast(_clname);
}

int MenuBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenuBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MenuBar::logoutSave(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MenuBar::exitSave(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MenuBar::signalCheckSaveOn(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
