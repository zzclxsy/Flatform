/****************************************************************************
** Meta object code from reading C++ file 'JHAppData.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Basic/AppData/JHAppData.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JHAppData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JHAppData_t {
    QByteArrayData data[11];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JHAppData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JHAppData_t qt_meta_stringdata_JHAppData = {
    {
QT_MOC_LITERAL(0, 0, 9), // "JHAppData"
QT_MOC_LITERAL(1, 10, 20), // "slotStateDataChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "sendDomainData"
QT_MOC_LITERAL(4, 47, 6), // "domain"
QT_MOC_LITERAL(5, 54, 4), // "data"
QT_MOC_LITERAL(6, 59, 12), // "addShareData"
QT_MOC_LITERAL(7, 72, 8), // "dataName"
QT_MOC_LITERAL(8, 81, 12), // "getShareData"
QT_MOC_LITERAL(9, 94, 13), // "slotStateData"
QT_MOC_LITERAL(10, 108, 12) // "JHListModel*"

    },
    "JHAppData\0slotStateDataChanged\0\0"
    "sendDomainData\0domain\0data\0addShareData\0"
    "dataName\0getShareData\0slotStateData\0"
    "JHListModel*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JHAppData[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   48, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    2,   35,    2, 0x02 /* Public */,
       6,    2,   40,    2, 0x02 /* Public */,
       8,    1,   45,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    5,
    QMetaType::QString, QMetaType::QString,    7,

 // properties: name, type, flags
       9, 0x80000000 | 10, 0x00495009,

 // properties: notify_signal_id
       0,

       0        // eod
};

void JHAppData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JHAppData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotStateDataChanged(); break;
        case 1: _t->sendDomainData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 2: _t->addShareData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: { QString _r = _t->getShareData((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JHAppData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JHAppData::slotStateDataChanged)) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< JHListModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<JHAppData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< JHListModel**>(_v) = _t->getSlotStateData(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject JHAppData::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_JHAppData.data,
    qt_meta_data_JHAppData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *JHAppData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JHAppData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JHAppData.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IJHAppData"))
        return static_cast< IJHAppData*>(this);
    if (!strcmp(_clname, "BObject"))
        return static_cast< BObject*>(this);
    return QObject::qt_metacast(_clname);
}

int JHAppData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void JHAppData::slotStateDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
