/********************************************************************************
** Form generated from reading UI file 'uye_islemleri.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UYE_ISLEMLERI_H
#define UI_UYE_ISLEMLERI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_uye_islemleri
{
public:
    QLabel *label_Uye_Ad;
    QPushButton *pushButton_Sil;
    QLineEdit *lineEdit_Uye_Ad;
    QPushButton *pushButton_Yeni_Kayit;
    QTableView *tableView_Uyeler;
    QLineEdit *lineEdit_Uye_Soyad;
    QLabel *label_Tum_Uyeler;
    QLabel *label_Uye_Soyad;
    QLabel *label_Uye_No;
    QLabel *label_Uye_Islemleri;
    QPushButton *pushButton_Guncelle;
    QLineEdit *lineEdit_Uye_No;

    void setupUi(QDialog *uye_islemleri)
    {
        if (uye_islemleri->objectName().isEmpty())
            uye_islemleri->setObjectName("uye_islemleri");
        uye_islemleri->resize(605, 359);
        label_Uye_Ad = new QLabel(uye_islemleri);
        label_Uye_Ad->setObjectName("label_Uye_Ad");
        label_Uye_Ad->setGeometry(QRect(350, 140, 101, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_Uye_Ad->setFont(font);
        pushButton_Sil = new QPushButton(uye_islemleri);
        pushButton_Sil->setObjectName("pushButton_Sil");
        pushButton_Sil->setGeometry(QRect(420, 280, 71, 31));
        QFont font1;
        font1.setBold(true);
        pushButton_Sil->setFont(font1);
        lineEdit_Uye_Ad = new QLineEdit(uye_islemleri);
        lineEdit_Uye_Ad->setObjectName("lineEdit_Uye_Ad");
        lineEdit_Uye_Ad->setGeometry(QRect(460, 141, 113, 31));
        pushButton_Yeni_Kayit = new QPushButton(uye_islemleri);
        pushButton_Yeni_Kayit->setObjectName("pushButton_Yeni_Kayit");
        pushButton_Yeni_Kayit->setGeometry(QRect(350, 240, 101, 31));
        pushButton_Yeni_Kayit->setFont(font1);
        tableView_Uyeler = new QTableView(uye_islemleri);
        tableView_Uyeler->setObjectName("tableView_Uyeler");
        tableView_Uyeler->setGeometry(QRect(40, 100, 261, 241));
        lineEdit_Uye_Soyad = new QLineEdit(uye_islemleri);
        lineEdit_Uye_Soyad->setObjectName("lineEdit_Uye_Soyad");
        lineEdit_Uye_Soyad->setGeometry(QRect(460, 181, 113, 31));
        label_Tum_Uyeler = new QLabel(uye_islemleri);
        label_Tum_Uyeler->setObjectName("label_Tum_Uyeler");
        label_Tum_Uyeler->setGeometry(QRect(40, 60, 201, 31));
        label_Tum_Uyeler->setFont(font);
        label_Uye_Soyad = new QLabel(uye_islemleri);
        label_Uye_Soyad->setObjectName("label_Uye_Soyad");
        label_Uye_Soyad->setGeometry(QRect(350, 180, 111, 31));
        label_Uye_Soyad->setFont(font);
        label_Uye_No = new QLabel(uye_islemleri);
        label_Uye_No->setObjectName("label_Uye_No");
        label_Uye_No->setGeometry(QRect(350, 100, 111, 31));
        label_Uye_No->setFont(font);
        label_Uye_Islemleri = new QLabel(uye_islemleri);
        label_Uye_Islemleri->setObjectName("label_Uye_Islemleri");
        label_Uye_Islemleri->setGeometry(QRect(220, 20, 161, 31));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        label_Uye_Islemleri->setFont(font2);
        label_Uye_Islemleri->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        pushButton_Guncelle = new QPushButton(uye_islemleri);
        pushButton_Guncelle->setObjectName("pushButton_Guncelle");
        pushButton_Guncelle->setGeometry(QRect(474, 240, 101, 31));
        pushButton_Guncelle->setFont(font1);
        lineEdit_Uye_No = new QLineEdit(uye_islemleri);
        lineEdit_Uye_No->setObjectName("lineEdit_Uye_No");
        lineEdit_Uye_No->setEnabled(false);
        lineEdit_Uye_No->setGeometry(QRect(460, 100, 113, 31));

        retranslateUi(uye_islemleri);

        QMetaObject::connectSlotsByName(uye_islemleri);
    } // setupUi

    void retranslateUi(QDialog *uye_islemleri)
    {
        uye_islemleri->setWindowTitle(QCoreApplication::translate("uye_islemleri", "Dialog", nullptr));
        label_Uye_Ad->setText(QCoreApplication::translate("uye_islemleri", "\303\234ye Ad:", nullptr));
        pushButton_Sil->setText(QCoreApplication::translate("uye_islemleri", "Sil", nullptr));
        pushButton_Yeni_Kayit->setText(QCoreApplication::translate("uye_islemleri", "Yeni Kay\304\261t", nullptr));
        label_Tum_Uyeler->setText(QCoreApplication::translate("uye_islemleri", "T\303\274m \303\234yeler ", nullptr));
        label_Uye_Soyad->setText(QCoreApplication::translate("uye_islemleri", "\303\234ye Soyad:", nullptr));
        label_Uye_No->setText(QCoreApplication::translate("uye_islemleri", "\303\234ye No:", nullptr));
        label_Uye_Islemleri->setText(QCoreApplication::translate("uye_islemleri", "\303\234YE \304\260\305\236LEMLER\304\260", nullptr));
        pushButton_Guncelle->setText(QCoreApplication::translate("uye_islemleri", "G\303\274ncelle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class uye_islemleri: public Ui_uye_islemleri {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UYE_ISLEMLERI_H
