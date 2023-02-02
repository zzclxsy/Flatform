/****************************************************************************
** Meta object code from reading C++ file 'JHSimpleNode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Basic/JHDataModel/JHSimpleNode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JHSimpleNode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JHSimpleNode_t {
    QByteArrayData data[16];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JHSimpleNode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JHSimpleNode_t qt_meta_stringdata_JHSimpleNode = {
    {
QT_MOC_LITERAL(0, 0, 12), // "JHSimpleNode"
QT_MOC_LITERAL(1, 13, 13), // "nodeIdChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "setData"
QT_MOC_LITERAL(4, 36, 4), // "data"
QT_MOC_LITERAL(5, 41, 11), // "setProperty"
QT_MOC_LITERAL(6, 53, 4), // "name"
QT_MOC_LITERAL(7, 58, 5), // "value"
QT_MOC_LITERAL(8, 64, 6), // "update"
QT_MOC_LITERAL(9, 71, 7), // "getData"
QT_MOC_LITERAL(10, 79, 11), // "hasProperty"
QT_MOC_LITERAL(11, 91, 11), // "getProperty"
QT_MOC_LITERAL(12, 103, 9), // "getString"
QT_MOC_LITERAL(13, 113, 11), // "getLongLong"
QT_MOC_LITERAL(14, 125, 12), // "toJsonObject"
QT_MOC_LITERAL(15, 138, 6) // "nodeId"

    },
    "JHSimpleNode\0nodeIdChanged\0\0setData\0"
    "data\0setProperty\0name\0value\0update\0"
    "getData\0hasProperty\0getProperty\0"
    "getString\0getLongLong\0toJsonObject\0"
    "nodeId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JHSimpleNode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       1,   90, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    1,   65,    2, 0x02 /* Public */,
       5,    2,   68,    2, 0x02 /* Public */,
       8,    1,   73,    2, 0x02 /* Public */,
       9,    0,   76,    2, 0x02 /* Public */,
      10,    1,   77,    2, 0x02 /* Public */,
      11,    1,   80,    2, 0x02 /* Public */,
      12,    1,   83,    2, 0x02 /* Public */,
      13,    1,   86,    2, 0x02 /* Public */,
      14,    0,   89,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QJsonObject,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonValue,    6,    7,
    QMetaType::QJsonObject, QMetaType::QJsonObject,    4,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    6,
    QMetaType::QJsonValue, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::LongLong, QMetaType::QString,    6,
    QMetaType::QJsonObject,

 // properties: name, type, flags
      15, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void JHSimpleNode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JHSimpleNode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nodeIdChanged(); break;
        case 1: _t->setData((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 2: _t->setProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonValue(*)>(_a[2]))); break;
        case 3: { QJsonObject _r = _t->update((*reinterpret_cast< const QJsonObject(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->getData(); break;
        case 5: { bool _r = _t->hasProperty((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { QJsonValue _r = _t->getProperty((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonValue*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { qint64 _r = _t->getLongLong((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = std::move(_r); }  break;
        case 9: { QJsonObject _r = _t->toJsonObject();
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JHSimpleNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JHSimpleNode::nodeIdChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<JHSimpleNode *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getNodeId(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject JHSimpleNode::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_JHSimpleNode.data,
    qt_meta_data_JHSimpleNode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *JHSimpleNode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JHSimpleNode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JHSimpleNode.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int JHSimpleNode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
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
void JHSimpleNode::nodeIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
