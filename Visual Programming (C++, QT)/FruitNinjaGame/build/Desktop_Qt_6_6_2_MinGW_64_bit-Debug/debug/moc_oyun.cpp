/****************************************************************************
** Meta object code from reading C++ file 'oyun.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../Users/metehan/Desktop/22100011024/oyun.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'oyun.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSkarpuzENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSkarpuzENDCLASS = QtMocHelpers::stringData(
    "karpuz",
    "karpuzu_kes",
    "",
    "karpuzu_gizle",
    "buyukluk_yeredusme"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSkarpuzENDCLASS_t {
    uint offsetsAndSizes[10];
    char stringdata0[7];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSkarpuzENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSkarpuzENDCLASS_t qt_meta_stringdata_CLASSkarpuzENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "karpuz"
        QT_MOC_LITERAL(7, 11),  // "karpuzu_kes"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 13),  // "karpuzu_gizle"
        QT_MOC_LITERAL(34, 18)   // "buyukluk_yeredusme"
    },
    "karpuz",
    "karpuzu_kes",
    "",
    "karpuzu_gizle",
    "buyukluk_yeredusme"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSkarpuzENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x0a,    1 /* Public */,
       3,    0,   33,    2, 0x0a,    2 /* Public */,
       4,    0,   34,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject karpuz::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_CLASSkarpuzENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSkarpuzENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSkarpuzENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<karpuz, std::true_type>,
        // method 'karpuzu_kes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'karpuzu_gizle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'buyukluk_yeredusme'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void karpuz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<karpuz *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->karpuzu_kes(); break;
        case 1: _t->karpuzu_gizle(); break;
        case 2: _t->buyukluk_yeredusme(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *karpuz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *karpuz::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSkarpuzENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int karpuz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
