/****************************************************************************
** Meta object code from reading C++ file 'kitap_islemleri.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../Users/metehan/Downloads/22100011024 (13)/22100011024/kitap_islemleri.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kitap_islemleri.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSkitap_islemleriENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSkitap_islemleriENDCLASS = QtMocHelpers::stringData(
    "kitap_islemleri",
    "on_pushButton_Yeni_Kayit_clicked",
    "",
    "on_pushButton_Guncelle_clicked",
    "on_pushButton_Sil_clicked",
    "on_tableView_Kitaplar_clicked",
    "QModelIndex",
    "index"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSkitap_islemleriENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[16];
    char stringdata1[33];
    char stringdata2[1];
    char stringdata3[31];
    char stringdata4[26];
    char stringdata5[30];
    char stringdata6[12];
    char stringdata7[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSkitap_islemleriENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSkitap_islemleriENDCLASS_t qt_meta_stringdata_CLASSkitap_islemleriENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "kitap_islemleri"
        QT_MOC_LITERAL(16, 32),  // "on_pushButton_Yeni_Kayit_clicked"
        QT_MOC_LITERAL(49, 0),  // ""
        QT_MOC_LITERAL(50, 30),  // "on_pushButton_Guncelle_clicked"
        QT_MOC_LITERAL(81, 25),  // "on_pushButton_Sil_clicked"
        QT_MOC_LITERAL(107, 29),  // "on_tableView_Kitaplar_clicked"
        QT_MOC_LITERAL(137, 11),  // "QModelIndex"
        QT_MOC_LITERAL(149, 5)   // "index"
    },
    "kitap_islemleri",
    "on_pushButton_Yeni_Kayit_clicked",
    "",
    "on_pushButton_Guncelle_clicked",
    "on_pushButton_Sil_clicked",
    "on_tableView_Kitaplar_clicked",
    "QModelIndex",
    "index"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSkitap_islemleriENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    0,   40,    2, 0x08,    3 /* Private */,
       5,    1,   41,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject kitap_islemleri::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSkitap_islemleriENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSkitap_islemleriENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSkitap_islemleriENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<kitap_islemleri, std::true_type>,
        // method 'on_pushButton_Yeni_Kayit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Guncelle_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Sil_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableView_Kitaplar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>
    >,
    nullptr
} };

void kitap_islemleri::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<kitap_islemleri *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_Yeni_Kayit_clicked(); break;
        case 1: _t->on_pushButton_Guncelle_clicked(); break;
        case 2: _t->on_pushButton_Sil_clicked(); break;
        case 3: _t->on_tableView_Kitaplar_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *kitap_islemleri::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *kitap_islemleri::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSkitap_islemleriENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int kitap_islemleri::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
