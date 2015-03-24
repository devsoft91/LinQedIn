/****************************************************************************
** Meta object code from reading C++ file 'clientwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LinQuedin/clientwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientWindow_t {
    QByteArrayData data[8];
    char stringdata[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientWindow_t qt_meta_stringdata_ClientWindow = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 12),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 19),
QT_MOC_LITERAL(4, 47, 20),
QT_MOC_LITERAL(5, 68, 6),
QT_MOC_LITERAL(6, 75, 12),
QT_MOC_LITERAL(7, 88, 14)
    },
    "ClientWindow\0signalSaveOn\0\0"
    "signalUpdateRicerca\0signalUpdateViewReti\0"
    "saveOn\0focusRicerca\0updateViewReti"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ClientWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientWindow *_t = static_cast<ClientWindow *>(_o);
        switch (_id) {
        case 0: _t->signalSaveOn(); break;
        case 1: _t->signalUpdateRicerca(); break;
        case 2: _t->signalUpdateViewReti(); break;
        case 3: _t->saveOn(); break;
        case 4: _t->focusRicerca(); break;
        case 5: _t->updateViewReti(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClientWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientWindow::signalSaveOn)) {
                *result = 0;
            }
        }
        {
            typedef void (ClientWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientWindow::signalUpdateRicerca)) {
                *result = 1;
            }
        }
        {
            typedef void (ClientWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientWindow::signalUpdateViewReti)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ClientWindow::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_ClientWindow.data,
      qt_meta_data_ClientWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *ClientWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClientWindow.stringdata))
        return static_cast<void*>(const_cast< ClientWindow*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int ClientWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
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
void ClientWindow::signalSaveOn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ClientWindow::signalUpdateRicerca()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ClientWindow::signalUpdateViewReti()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
