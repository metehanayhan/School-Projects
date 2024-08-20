/****************************************************************************
** Meta object code from reading C++ file 'odunc_alma_islemleri.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../Users/metehan/Downloads/22100011024 (13)/22100011024/odunc_alma_islemleri.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'odunc_alma_islemleri.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSodunc_alma_islemleriENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSodunc_alma_islemleriENDCLASS = QtMocHelpers::stringData(
    "odunc_alma_islemleri",
    "on_pushButton_Odunc_Al_clicked",
    "",
    "on_tableView_Tum_Kitaplar_clicked",
    "QModelIndex",
    "index",
    "on_tableView_Tum_Uyeler_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSodunc_alma_islemleriENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[21];
    char stringdata1[31];
    char stringdata2[1];
    char stringdata3[34];
    char stringdata4[12];
    char stringdata5[6];
    char stringdata6[32];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSodunc_alma_islemleriENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSodunc_alma_islemleriENDCLASS_t qt_meta_stringdata_CLASSodunc_alma_islemleriENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20),  // "odunc_alma_islemleri"
        QT_MOC_LITERAL(21, 30),  // "on_pushButton_Odunc_Al_clicked"
        QT_MOC_LITERAL(52, 0),  // ""
        QT_MOC_LITERAL(53, 33),  // "on_tableView_Tum_Kitaplar_cli..."
        QT_MOC_LITERAL(87, 11),  // "QModelIndex"
        QT_MOC_LITERAL(99, 5),  // "index"
        QT_MOC_LITERAL(105, 31)   // "on_tableView_Tum_Uyeler_clicked"
    },
    "odunc_alma_islemleri",
    "on_pushButton_Odunc_Al_clicked",
    "",
    "on_tableView_Tum_Kitaplar_clicked",
    "QModelIndex",
    "index",
    "on_tableView_Tum_Uyeler_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSodunc_alma_islemleriENDCLASS[] = {

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
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    1,   33,    2, 0x08,    2 /* Private */,
       6,    1,   36,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject odunc_alma_islemleri::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSodunc_alma_islemleriENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSodunc_alma_islemleriENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSodunc_alma_islemleriENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<odunc_alma_islemleri, std::true_type>,
        // method 'on_pushButton_Odunc_Al_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableView_Tum_Kitaplar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_tableView_Tum_Uyeler_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>
    >,
    nullptr
} };

void odunc_alma_islemleri::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<odunc_alma_islemleri *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_Odunc_Al_clicked(); break;
        case 1: _t->on_tableView_Tum_Kitaplar_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->on_tableView_Tum_Uyeler_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *odunc_alma_islemleri::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *odunc_alma_islemleri::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSodunc_alma_islemleriENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int odunc_alma_islemleri::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
