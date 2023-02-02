/****************************************************************************
** Meta object code from reading C++ file 'JHListModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Basic/JHDataModel/JHListModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JHListModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JHListModel_t {
    QByteArrayData data[17];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JHListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JHListModel_t qt_meta_stringdata_JHListModel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "JHListModel"
QT_MOC_LITERAL(1, 12, 12), // "nodeInserted"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 6), // "nodeId"
QT_MOC_LITERAL(4, 33, 3), // "pos"
QT_MOC_LITERAL(5, 37, 6), // "append"
QT_MOC_LITERAL(6, 44, 3), // "key"
QT_MOC_LITERAL(7, 48, 4), // "data"
QT_MOC_LITERAL(8, 53, 8), // "validate"
QT_MOC_LITERAL(9, 62, 6), // "insert"
QT_MOC_LITERAL(10, 69, 5), // "count"
QT_MOC_LITERAL(11, 75, 11), // "removeFirst"
QT_MOC_LITERAL(12, 87, 10), // "removeLast"
QT_MOC_LITERAL(13, 98, 2), // "at"
QT_MOC_LITERAL(14, 101, 5), // "index"
QT_MOC_LITERAL(15, 107, 4), // "dump"
QT_MOC_LITERAL(16, 112, 8) // "filePath"

    },
    "JHListModel\0nodeInserted\0\0nodeId\0pos\0"
    "append\0key\0data\0validate\0insert\0count\0"
    "removeFirst\0removeLast\0at\0index\0dump\0"
    "filePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JHListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    3,   79,    2, 0x02 /* Public */,
       5,    2,   86,    2, 0x22 /* Public | MethodCloned */,
       9,    4,   91,    2, 0x02 /* Public */,
       9,    3,  100,    2, 0x22 /* Public | MethodCloned */,
      10,    0,  107,    2, 0x02 /* Public */,
      11,    1,  108,    2, 0x02 /* Public */,
      11,    0,  111,    2, 0x22 /* Public | MethodCloned */,
      12,    1,  112,    2, 0x02 /* Public */,
      12,    0,  115,    2, 0x22 /* Public | MethodCloned */,
      13,    1,  116,    2, 0x02 /* Public */,
      15,    1,  119,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,

 // methods: parameters
    QMetaType::Int, QMetaType::QString, QMetaType::QJsonObject, QMetaType::Bool,    6,    7,    8,
    QMetaType::Int, QMetaType::QString, QMetaType::QJsonObject,    6,    7,
    QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QJsonObject, QMetaType::Bool,    4,    6,    7,    8,
    QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QJsonObject,    4,    6,    7,
    QMetaType::Int,
    QMetaType::Int, QMetaType::Bool,    8,
    QMetaType::Int,
    QMetaType::Int, QMetaType::Bool,    8,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void JHListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JHListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nodeInserted((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: { int _r = _t->append((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->append((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->insert((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QJsonObject(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->insert((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QJsonObject(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->removeFirst((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->removeFirst();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->removeLast((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->removeLast();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->at((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->dump((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JHListModel::*)(const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JHListModel::nodeInserted)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject JHListModel::staticMetaObject = { {
    &JHSimpleModel::staticMetaObject,
    qt_meta_stringdata_JHListModel.data,
    qt_meta_data_JHListModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *JHListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JHListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JHListModel.stringdata0))
        return static_cast<void*>(this);
    return JHSimpleModel::qt_metacast(_clname);
}

int JHListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = JHSimpleModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void JHListModel::nodeInserted(const QString & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
