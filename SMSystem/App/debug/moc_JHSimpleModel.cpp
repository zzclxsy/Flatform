/****************************************************************************
** Meta object code from reading C++ file 'JHSimpleModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Basic/JHDataModel/JHSimpleModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JHSimpleModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JHSimpleModel_t {
    QByteArrayData data[30];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JHSimpleModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JHSimpleModel_t qt_meta_stringdata_JHSimpleModel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "JHSimpleModel"
QT_MOC_LITERAL(1, 14, 12), // "modelChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "nodeAdded"
QT_MOC_LITERAL(4, 38, 6), // "nodeId"
QT_MOC_LITERAL(5, 45, 17), // "nodeAboutToRemove"
QT_MOC_LITERAL(6, 63, 11), // "nodeRemoved"
QT_MOC_LITERAL(7, 75, 11), // "nodeChanged"
QT_MOC_LITERAL(8, 87, 11), // "updatedData"
QT_MOC_LITERAL(9, 99, 3), // "add"
QT_MOC_LITERAL(10, 103, 3), // "key"
QT_MOC_LITERAL(11, 107, 4), // "data"
QT_MOC_LITERAL(12, 112, 8), // "validate"
QT_MOC_LITERAL(13, 121, 6), // "remove"
QT_MOC_LITERAL(14, 128, 6), // "update"
QT_MOC_LITERAL(15, 135, 5), // "count"
QT_MOC_LITERAL(16, 141, 8), // "contains"
QT_MOC_LITERAL(17, 150, 5), // "clear"
QT_MOC_LITERAL(18, 156, 4), // "keys"
QT_MOC_LITERAL(19, 161, 7), // "getData"
QT_MOC_LITERAL(20, 169, 11), // "getProperty"
QT_MOC_LITERAL(21, 181, 4), // "name"
QT_MOC_LITERAL(22, 186, 7), // "findOne"
QT_MOC_LITERAL(23, 194, 5), // "value"
QT_MOC_LITERAL(24, 200, 9), // "condition"
QT_MOC_LITERAL(25, 210, 8), // "findMany"
QT_MOC_LITERAL(26, 219, 10), // "updateMany"
QT_MOC_LITERAL(27, 230, 10), // "invalidate"
QT_MOC_LITERAL(28, 241, 4), // "dump"
QT_MOC_LITERAL(29, 246, 8) // "filePath"

    },
    "JHSimpleModel\0modelChanged\0\0nodeAdded\0"
    "nodeId\0nodeAboutToRemove\0nodeRemoved\0"
    "nodeChanged\0updatedData\0add\0key\0data\0"
    "validate\0remove\0update\0count\0contains\0"
    "clear\0keys\0getData\0getProperty\0name\0"
    "findOne\0value\0condition\0findMany\0"
    "updateMany\0invalidate\0dump\0filePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JHSimpleModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  139,    2, 0x06 /* Public */,
       3,    1,  140,    2, 0x06 /* Public */,
       5,    1,  143,    2, 0x06 /* Public */,
       6,    1,  146,    2, 0x06 /* Public */,
       7,    2,  149,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       9,    3,  154,    2, 0x02 /* Public */,
       9,    2,  161,    2, 0x22 /* Public | MethodCloned */,
      13,    2,  166,    2, 0x02 /* Public */,
      13,    1,  171,    2, 0x22 /* Public | MethodCloned */,
      14,    3,  174,    2, 0x02 /* Public */,
      14,    2,  181,    2, 0x22 /* Public | MethodCloned */,
      15,    0,  186,    2, 0x02 /* Public */,
      16,    1,  187,    2, 0x02 /* Public */,
      17,    0,  190,    2, 0x02 /* Public */,
      18,    0,  191,    2, 0x02 /* Public */,
      19,    1,  192,    2, 0x02 /* Public */,
      20,    2,  195,    2, 0x02 /* Public */,
      22,    2,  200,    2, 0x02 /* Public */,
      22,    1,  205,    2, 0x02 /* Public */,
      25,    2,  208,    2, 0x02 /* Public */,
      25,    1,  213,    2, 0x02 /* Public */,
      26,    3,  216,    2, 0x02 /* Public */,
      26,    2,  223,    2, 0x22 /* Public | MethodCloned */,
      27,    0,  228,    2, 0x02 /* Public */,
      28,    1,  229,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    4,    8,

 // methods: parameters
    QMetaType::Int, QMetaType::QString, QMetaType::QJsonObject, QMetaType::Bool,   10,   11,   12,
    QMetaType::Int, QMetaType::QString, QMetaType::QJsonObject,   10,   11,
    QMetaType::Int, QMetaType::QString, QMetaType::Bool,   10,   12,
    QMetaType::Int, QMetaType::QString,   10,
    QMetaType::QJsonObject, QMetaType::QString, QMetaType::QJsonObject, QMetaType::Bool,   10,   11,   12,
    QMetaType::QJsonObject, QMetaType::QString, QMetaType::QJsonObject,   10,   11,
    QMetaType::Int,
    QMetaType::Bool, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::QStringList,
    QMetaType::QJsonObject, QMetaType::QString,   10,
    QMetaType::QJsonValue, QMetaType::QString, QMetaType::QString,   10,   21,
    QMetaType::QString, QMetaType::QString, QMetaType::QJsonValue,   21,   23,
    QMetaType::QString, QMetaType::QJsonObject,   24,
    QMetaType::QStringList, QMetaType::QString, QMetaType::QJsonValue,   21,   23,
    QMetaType::QStringList, QMetaType::QJsonObject,   24,
    QMetaType::Int, QMetaType::QJsonObject, QMetaType::QJsonObject, QMetaType::Bool,   24,   11,   12,
    QMetaType::Int, QMetaType::QJsonObject, QMetaType::QJsonObject,   24,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,

       0        // eod
};

void JHSimpleModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JHSimpleModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modelChanged(); break;
        case 1: _t->nodeAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->nodeAboutToRemove((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->nodeRemoved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->nodeChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2]))); break;
        case 5: { int _r = _t->add((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->add((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->remove((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->remove((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { QJsonObject _r = _t->update((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 10: { QJsonObject _r = _t->update((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->contains((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->clear(); break;
        case 14: { QStringList _r = _t->keys();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 15: { QJsonObject _r = _t->getData((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 16: { QJsonValue _r = _t->getProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QJsonValue*>(_a[0]) = std::move(_r); }  break;
        case 17: { QString _r = _t->findOne((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonValue(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 18: { QString _r = _t->findOne((*reinterpret_cast< const QJsonObject(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: { QStringList _r = _t->findMany((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonValue(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 20: { QStringList _r = _t->findMany((*reinterpret_cast< const QJsonObject(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 21: { int _r = _t->updateMany((*reinterpret_cast< const QJsonObject(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 22: { int _r = _t->updateMany((*reinterpret_cast< const QJsonObject(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->invalidate(); break;
        case 24: _t->dump((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JHSimpleModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JHSimpleModel::modelChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (JHSimpleModel::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JHSimpleModel::nodeAdded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (JHSimpleModel::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JHSimpleModel::nodeAboutToRemove)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (JHSimpleModel::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JHSimpleModel::nodeRemoved)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (JHSimpleModel::*)(const QString & , const QJsonObject & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JHSimpleModel::nodeChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject JHSimpleModel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_JHSimpleModel.data,
    qt_meta_data_JHSimpleModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *JHSimpleModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JHSimpleModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JHSimpleModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int JHSimpleModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void JHSimpleModel::modelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void JHSimpleModel::nodeAdded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JHSimpleModel::nodeAboutToRemove(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void JHSimpleModel::nodeRemoved(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void JHSimpleModel::nodeChanged(const QString & _t1, const QJsonObject & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
