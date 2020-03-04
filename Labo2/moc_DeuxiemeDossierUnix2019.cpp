/****************************************************************************
** Meta object code from reading C++ file 'DeuxiemeDossierUnix2019.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DeuxiemeDossierUnix2019.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DeuxiemeDossierUnix2019.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainDeuxiemeDossierUnix2019[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      29,   28,   28,   28, 0x08,
      58,   28,   28,   28, 0x08,
      85,   28,   28,   28, 0x08,
     113,   28,   28,   28, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainDeuxiemeDossierUnix2019[] = {
    "MainDeuxiemeDossierUnix2019\0\0"
    "on_ButtonPrecedent_clicked()\0"
    "on_ButtonSuivant_clicked()\0"
    "on_ButtonModifier_clicked()\0"
    "on_ButtonTerminer_clicked()\0"
};

void MainDeuxiemeDossierUnix2019::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainDeuxiemeDossierUnix2019 *_t = static_cast<MainDeuxiemeDossierUnix2019 *>(_o);
        switch (_id) {
        case 0: _t->on_ButtonPrecedent_clicked(); break;
        case 1: _t->on_ButtonSuivant_clicked(); break;
        case 2: _t->on_ButtonModifier_clicked(); break;
        case 3: _t->on_ButtonTerminer_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainDeuxiemeDossierUnix2019::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainDeuxiemeDossierUnix2019::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainDeuxiemeDossierUnix2019,
      qt_meta_data_MainDeuxiemeDossierUnix2019, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainDeuxiemeDossierUnix2019::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainDeuxiemeDossierUnix2019::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainDeuxiemeDossierUnix2019::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainDeuxiemeDossierUnix2019))
        return static_cast<void*>(const_cast< MainDeuxiemeDossierUnix2019*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainDeuxiemeDossierUnix2019::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
