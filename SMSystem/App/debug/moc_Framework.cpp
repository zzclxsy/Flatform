/****************************************************************************
** Meta object code from reading C++ file 'Framework.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Basic/Framework/Framework.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Framework.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Framework_t {
    QByteArrayData data[9];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Framework_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Framework_t qt_meta_stringdata_Framework = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Framework"
QT_MOC_LITERAL(1, 10, 20), // "objectManagerChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "appDataChanged"
QT_MOC_LITERAL(4, 47, 18), // "applicationDirPath"
QT_MOC_LITERAL(5, 66, 13), // "objectManager"
QT_MOC_LITERAL(6, 80, 10), // "ObjectMgr*"
QT_MOC_LITERAL(7, 91, 7), // "AppData"
QT_MOC_LITERAL(8, 99, 10) // "JHAppData*"

    },
    "Framework\0objectManagerChanged\0\0"
    "appDataChanged\0applicationDirPath\0"
    "objectManager\0ObjectMgr*\0AppData\0"
    "JHAppData*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Framework[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       2,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::QString,

 // properties: name, type, flags
       5, 0x80000000 | 6, 0x0049510b,
       7, 0x80000000 | 8, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void Framework::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Framework *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->objectManagerChanged(); break;
        case 1: _t->appDataChanged(); break;
        case 2: { QString _r = _t->applicationDirPath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Framework::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Framework::objectManagerChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Framework::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Framework::appDataChanged)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< JHAppData* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ObjectMgr* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Framework *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< ObjectMgr**>(_v) = _t->getObjectManager(); break;
        case 1: *reinterpret_cast< JHAppData**>(_v) = _t->getAppData(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Framework *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setObjectManager(*reinterpret_cast< ObjectMgr**>(_v)); break;
        case 1: _t->setAppData(*reinterpret_cast< JHAppData**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Framework::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Framework.data,
    qt_meta_data_Framework,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Framework::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Framework::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Framework.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Framework::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Framework::objectManagerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Framework::appDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
