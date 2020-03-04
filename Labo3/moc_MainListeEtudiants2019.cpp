/****************************************************************************
** Meta object code from reading C++ file 'MainListeEtudiants2019.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainListeEtudiants2019.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainListeEtudiants2019.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainListeEtudiants2019[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x08,
      46,   23,   23,   23, 0x08,
      73,   23,   23,   23, 0x08,
     101,   23,   23,   23, 0x08,
     137,   23,  125,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainListeEtudiants2019[] = {
    "MainListeEtudiants2019\0\0on_ButtonOk_clicked()\0"
    "on_ButtonEffacer_clicked()\0"
    "on_ButtonTerminer_clicked()\0"
    "setGroupe1(const char*)\0const char*\0"
    "getGroupe1()\0"
};

void MainListeEtudiants2019::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainListeEtudiants2019 *_t = static_cast<MainListeEtudiants2019 *>(_o);
        switch (_id) {
        case 0: _t->on_ButtonOk_clicked(); break;
        case 1: _t->on_ButtonEffacer_clicked(); break;
        case 2: _t->on_ButtonTerminer_clicked(); break;
        case 3: _t->setGroupe1((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 4: { const char* _r = _t->getGroupe1();
            if (_a[0]) *reinterpret_cast< const char**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainListeEtudiants2019::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainListeEtudiants2019::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainListeEtudiants2019,
      qt_meta_data_MainListeEtudiants2019, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainListeEtudiants2019::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainListeEtudiants2019::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainListeEtudiants2019::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainListeEtudiants2019))
        return static_cast<void*>(const_cast< MainListeEtudiants2019*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainListeEtudiants2019::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
