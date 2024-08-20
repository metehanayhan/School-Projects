/********************************************************************************
** Form generated from reading UI file 'kitap_islemleri.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KITAP_ISLEMLERI_H
#define UI_KITAP_ISLEMLERI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_kitap_islemleri
{
public:
    QLabel *label_Kitap_Islemleri;
    QLabel *label_Kitap_Ad;
    QLabel *label_Stok;
    QTableView *tableView_Kitaplar;
    QLineEdit *lineEdit_Kitap_No;
    QLabel *label_Kitap_No;
    QPushButton *pushButton_Guncelle;
    QPushButton *pushButton_Sil;
    QLineEdit *lineEdit_Kitap_Ad;
    QPushButton *pushButton_Yeni_Kayit;
    QLabel *label_Tum_Kitaplar;
    QLineEdit *lineEdit_Stok;
    QTableView *tableView_Odunc_Alinma;
    QTableView *tableView_Daha_Onceden_Odunc_Alinma;
    QLabel *label_Odunc_Alinma;
    QLabel *label_Daha_Onceden_Odunc_Alinma;

    void setupUi(QDialog *kitap_islemleri)
    {
        if (kitap_islemleri->objectName().isEmpty())
            kitap_islemleri->setObjectName("kitap_islemleri");
        kitap_islemleri->resize(691, 652);
        label_Kitap_Islemleri = new QLabel(kitap_islemleri);
        label_Kitap_Islemleri->setObjectName("label_Kitap_Islemleri");
        label_Kitap_Islemleri->setGeometry(QRect(240, 10, 181, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_Kitap_Islemleri->setFont(font);
        label_Kitap_Islemleri->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_Kitap_Ad = new QLabel(kitap_islemleri);
        label_Kitap_Ad->setObjectName("label_Kitap_Ad");
        label_Kitap_Ad->setGeometry(QRect(330, 110, 101, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_Kitap_Ad->setFont(font1);
        label_Stok = new QLabel(kitap_islemleri);
        label_Stok->setObjectName("label_Stok");
        label_Stok->setGeometry(QRect(330, 150, 91, 31));
        label_Stok->setFont(font1);
        tableView_Kitaplar = new QTableView(kitap_islemleri);
        tableView_Kitaplar->setObjectName("tableView_Kitaplar");
        tableView_Kitaplar->setGeometry(QRect(20, 70, 281, 271));
        lineEdit_Kitap_No = new QLineEdit(kitap_islemleri);
        lineEdit_Kitap_No->setObjectName("lineEdit_Kitap_No");
        lineEdit_Kitap_No->setEnabled(false);
        lineEdit_Kitap_No->setGeometry(QRect(460, 70, 151, 31));
        label_Kitap_No = new QLabel(kitap_islemleri);
        label_Kitap_No->setObjectName("label_Kitap_No");
        label_Kitap_No->setGeometry(QRect(330, 70, 81, 31));
        label_Kitap_No->setFont(font1);
        pushButton_Guncelle = new QPushButton(kitap_islemleri);
        pushButton_Guncelle->setObjectName("pushButton_Guncelle");
        pushButton_Guncelle->setGeometry(QRect(520, 220, 91, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        pushButton_Guncelle->setFont(font2);
        pushButton_Sil = new QPushButton(kitap_islemleri);
        pushButton_Sil->setObjectName("pushButton_Sil");
        pushButton_Sil->setGeometry(QRect(420, 270, 101, 31));
        pushButton_Sil->setFont(font2);
        lineEdit_Kitap_Ad = new QLineEdit(kitap_islemleri);
        lineEdit_Kitap_Ad->setObjectName("lineEdit_Kitap_Ad");
        lineEdit_Kitap_Ad->setGeometry(QRect(460, 110, 151, 31));
        pushButton_Yeni_Kayit = new QPushButton(kitap_islemleri);
        pushButton_Yeni_Kayit->setObjectName("pushButton_Yeni_Kayit");
        pushButton_Yeni_Kayit->setGeometry(QRect(330, 220, 91, 31));
        pushButton_Yeni_Kayit->setFont(font2);
        label_Tum_Kitaplar = new QLabel(kitap_islemleri);
        label_Tum_Kitaplar->setObjectName("label_Tum_Kitaplar");
        label_Tum_Kitaplar->setGeometry(QRect(20, 40, 201, 21));
        label_Tum_Kitaplar->setFont(font1);
        lineEdit_Stok = new QLineEdit(kitap_islemleri);
        lineEdit_Stok->setObjectName("lineEdit_Stok");
        lineEdit_Stok->setGeometry(QRect(460, 150, 151, 31));
        tableView_Odunc_Alinma = new QTableView(kitap_islemleri);
        tableView_Odunc_Alinma->setObjectName("tableView_Odunc_Alinma");
        tableView_Odunc_Alinma->setGeometry(QRect(20, 380, 311, 251));
        tableView_Daha_Onceden_Odunc_Alinma = new QTableView(kitap_islemleri);
        tableView_Daha_Onceden_Odunc_Alinma->setObjectName("tableView_Daha_Onceden_Odunc_Alinma");
        tableView_Daha_Onceden_Odunc_Alinma->setGeometry(QRect(350, 380, 321, 251));
        label_Odunc_Alinma = new QLabel(kitap_islemleri);
        label_Odunc_Alinma->setObjectName("label_Odunc_Alinma");
        label_Odunc_Alinma->setGeometry(QRect(30, 350, 301, 21));
        label_Odunc_Alinma->setFont(font2);
        label_Daha_Onceden_Odunc_Alinma = new QLabel(kitap_islemleri);
        label_Daha_Onceden_Odunc_Alinma->setObjectName("label_Daha_Onceden_Odunc_Alinma");
        label_Daha_Onceden_Odunc_Alinma->setGeometry(QRect(340, 350, 341, 21));
        label_Daha_Onceden_Odunc_Alinma->setFont(font2);

        retranslateUi(kitap_islemleri);

        QMetaObject::connectSlotsByName(kitap_islemleri);
    } // setupUi

    void retranslateUi(QDialog *kitap_islemleri)
    {
        kitap_islemleri->setWindowTitle(QCoreApplication::translate("kitap_islemleri", "Dialog", nullptr));
        label_Kitap_Islemleri->setText(QCoreApplication::translate("kitap_islemleri", "K\304\260TAP \304\260\305\236LEMLER\304\260", nullptr));
        label_Kitap_Ad->setText(QCoreApplication::translate("kitap_islemleri", "Kitap Ad:", nullptr));
        label_Stok->setText(QCoreApplication::translate("kitap_islemleri", "Stok:", nullptr));
        label_Kitap_No->setText(QCoreApplication::translate("kitap_islemleri", "Kitap No:", nullptr));
        pushButton_Guncelle->setText(QCoreApplication::translate("kitap_islemleri", "G\303\274ncelle", nullptr));
        pushButton_Sil->setText(QCoreApplication::translate("kitap_islemleri", "Sil", nullptr));
        pushButton_Yeni_Kayit->setText(QCoreApplication::translate("kitap_islemleri", "Yeni Kay\304\261t", nullptr));
        label_Tum_Kitaplar->setText(QCoreApplication::translate("kitap_islemleri", "T\303\274m Kitaplar ", nullptr));
        label_Odunc_Alinma->setText(QCoreApplication::translate("kitap_islemleri", "Se\303\247ilen Kitab\304\261n \303\226d\303\274n\303\247 Al\304\261nma Durumu", nullptr));
        label_Daha_Onceden_Odunc_Alinma->setText(QCoreApplication::translate("kitap_islemleri", "Se\303\247ilen Kitab\304\261n Daha \303\226nceden \303\226d\303\274n\303\247 Al\304\261nma Durumu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class kitap_islemleri: public Ui_kitap_islemleri {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KITAP_ISLEMLERI_H
