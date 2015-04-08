/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LinQuedin/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 18),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 18),
QT_MOC_LITERAL(4, 50, 15),
QT_MOC_LITERAL(5, 66, 18),
QT_MOC_LITERAL(6, 85, 17),
QT_MOC_LITERAL(7, 103, 17),
QT_MOC_LITERAL(8, 121, 16),
QT_MOC_LITERAL(9, 138, 16),
QT_MOC_LITERAL(10, 155, 11),
QT_MOC_LITERAL(11, 167, 21),
QT_MOC_LITERAL(12, 189, 20),
QT_MOC_LITERAL(13, 210, 11),
QT_MOC_LITERAL(14, 222, 11),
QT_MOC_LITERAL(15, 234, 11),
QT_MOC_LITERAL(16, 246, 10),
QT_MOC_LITERAL(17, 257, 6),
QT_MOC_LITERAL(18, 264, 4),
QT_MOC_LITERAL(19, 269, 15),
QT_MOC_LITERAL(20, 285, 17),
QT_MOC_LITERAL(21, 303, 8),
QT_MOC_LITERAL(22, 312, 10),
QT_MOC_LITERAL(23, 323, 12)
    },
    "MainWindow\0disableNewInstance\0\0"
    "enableSaveInstance\0signalSaveState\0"
    "signalDiscardState\0signalCancelState\0"
    "signalDisableFind\0signalEnableFind\0"
    "signalAddRicerca\0aboutToQuit\0"
    "showLoginClientWindow\0showLoginAdminWindow\0"
    "saveConfirm\0saveEnabler\0loginClient\0"
    "loginAdmin\0logout\0exit\0callFormRicerca\0"
    "catchMessageToSet\0showInfo\0closeEvent\0"
    "QCloseEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x06 /* Public */,
       3,    0,  120,    2, 0x06 /* Public */,
       4,    0,  121,    2, 0x06 /* Public */,
       5,    0,  122,    2, 0x06 /* Public */,
       6,    0,  123,    2, 0x06 /* Public */,
       7,    0,  124,    2, 0x06 /* Public */,
       8,    0,  125,    2, 0x06 /* Public */,
       9,    0,  126,    2, 0x06 /* Public */,
      10,    0,  127,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  128,    2, 0x0a /* Public */,
      12,    0,  129,    2, 0x0a /* Public */,
      13,    0,  130,    2, 0x0a /* Public */,
      14,    0,  131,    2, 0x0a /* Public */,
      15,    1,  132,    2, 0x0a /* Public */,
      16,    1,  135,    2, 0x0a /* Public */,
      17,    1,  138,    2, 0x0a /* Public */,
      18,    1,  141,    2, 0x0a /* Public */,
      19,    0,  144,    2, 0x0a /* Public */,
      20,    1,  145,    2, 0x0a /* Public */,
      21,    0,  148,    2, 0x0a /* Public */,
      22,    1,  149,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->disableNewInstance(); break;
        case 1: _t->enableSaveInstance(); break;
        case 2: _t->signalSaveState(); break;
        case 3: _t->signalDiscardState(); break;
        case 4: _t->signalCancelState(); break;
        case 5: _t->signalDisableFind(); break;
        case 6: _t->signalEnableFind(); break;
        case 7: _t->signalAddRicerca(); break;
        case 8: _t->aboutToQuit(); break;
        case 9: _t->showLoginClientWindow(); break;
        case 10: _t->showLoginAdminWindow(); break;
        case 11: _t->saveConfirm(); break;
        case 12: _t->saveEnabler(); break;
        case 13: _t->loginClient((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->loginAdmin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->logout((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->exit((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->callFormRicerca(); break;
        case 18: _t->catchMessageToSet((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->showInfo(); break;
        case 20: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::disableNewInstance)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::enableSaveInstance)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalSaveState)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalDiscardState)) {
                *result = 3;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalCancelState)) {
                *result = 4;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalDisableFind)) {
                *result = 5;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalEnableFind)) {
                *result = 6;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalAddRicerca)) {
                *result = 7;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::aboutToQuit)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::disableNewInstance()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainWindow::enableSaveInstance()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainWindow::signalSaveState()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainWindow::signalDiscardState()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainWindow::signalCancelState()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MainWindow::signalDisableFind()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MainWindow::signalEnableFind()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MainWindow::signalAddRicerca()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void MainWindow::aboutToQuit()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
