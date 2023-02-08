/****************************************************************************
** Meta object code from reading C++ file 'JHStudentListModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../JHStudentListModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JHStudentListModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JHStudentListModel_t {
    QByteArrayData data[10];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JHStudentListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JHStudentListModel_t qt_meta_stringdata_JHStudentListModel = {
    {
QT_MOC_LITERAL(0, 0, 18), // "JHStudentListModel"
QT_MOC_LITERAL(1, 19, 10), // "initialize"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "addStudent"
QT_MOC_LITERAL(4, 42, 11), // "studentInfo"
QT_MOC_LITERAL(5, 54, 17), // "updataStudentInfo"
QT_MOC_LITERAL(6, 72, 5), // "index"
QT_MOC_LITERAL(7, 78, 3), // "key"
QT_MOC_LITERAL(8, 82, 5), // "value"
QT_MOC_LITERAL(9, 88, 13) // "deleteStudent"

    },
    "JHStudentListModel\0initialize\0\0"
    "addStudent\0studentInfo\0updataStudentInfo\0"
    "index\0key\0value\0deleteStudent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JHStudentListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x02 /* Public */,
       3,    1,   35,    2, 0x02 /* Public */,
       5,    3,   38,    2, 0x02 /* Public */,
       9,    1,   45,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    6,    7,    8,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void JHStudentListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JHStudentListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initialize(); break;
        case 1: _t->addStudent((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 2: _t->updataStudentInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->deleteStudent((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject JHStudentListModel::staticMetaObject = { {
    &JHListViewModel::staticMetaObject,
    qt_meta_stringdata_JHStudentListModel.data,
    qt_meta_data_JHStudentListModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *JHStudentListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JHStudentListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JHStudentListModel.stringdata0))
        return static_cast<void*>(this);
    return JHListViewModel::qt_metacast(_clname);
}

int JHStudentListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = JHListViewModel::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
