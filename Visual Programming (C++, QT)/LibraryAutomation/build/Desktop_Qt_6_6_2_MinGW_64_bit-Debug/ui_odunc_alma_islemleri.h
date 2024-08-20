/********************************************************************************
** Form generated from reading UI file 'odunc_alma_islemleri.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ODUNC_ALMA_ISLEMLERI_H
#define UI_ODUNC_ALMA_ISLEMLERI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_odunc_alma_islemleri
{
public:
    QTableView *tableView_Odunc_Alinan_Kitaplar_Listesi;
    QLabel *label_Uye_No;
    QLineEdit *lineEdit_Uye_No;
    QTableView *tableView_Tum_Uyeler;
    QLabel *label_Odunc_Alinan_Kitaplar_Listesi;
    QLabel *label_Stok;
    QLabel *label_Tum_Kitaplar;
    QLabel *label_Odunc_Alma_Islemleri;
    QLineEdit *lineEdit_Kitap_No;
    QPushButton *pushButton_Odunc_Al;
    QLabel *label_Tum_Uyeler;
    QLabel *label_Kitap_No;
    QTableView *tableView_Tum_Kitaplar;
    QDateEdit *dateEdit_Odunc_Alma_Tarihi;

    void setupUi(QDialog *odunc_alma_islemleri)
    {
        if (odunc_alma_islemleri->objectName().isEmpty())
            odunc_alma_islemleri->setObjectName("odunc_alma_islemleri");
        odunc_alma_islemleri->resize(691, 595);
        tableView_Odunc_Alinan_Kitaplar_Listesi = new QTableView(odunc_alma_islemleri);
        tableView_Odunc_Alinan_Kitaplar_Listesi->setObjectName("tableView_Odunc_Alinan_Kitaplar_Listesi");
        tableView_Odunc_Alinan_Kitaplar_Listesi->setGeometry(QRect(370, 340, 291, 231));
        label_Uye_No = new QLabel(odunc_alma_islemleri);
        label_Uye_No->setObjectName("label_Uye_No");
        label_Uye_No->setGeometry(QRect(40, 340, 101, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_Uye_No->setFont(font);
        lineEdit_Uye_No = new QLineEdit(odunc_alma_islemleri);
        lineEdit_Uye_No->setObjectName("lineEdit_Uye_No");
        lineEdit_Uye_No->setEnabled(false);
        lineEdit_Uye_No->setGeometry(QRect(170, 340, 151, 31));
        tableView_Tum_Uyeler = new QTableView(odunc_alma_islemleri);
        tableView_Tum_Uyeler->setObjectName("tableView_Tum_Uyeler");
        tableView_Tum_Uyeler->setGeometry(QRect(40, 80, 281, 221));
        label_Odunc_Alinan_Kitaplar_Listesi = new QLabel(odunc_alma_islemleri);
        label_Odunc_Alinan_Kitaplar_Listesi->setObjectName("label_Odunc_Alinan_Kitaplar_Listesi");
        label_Odunc_Alinan_Kitaplar_Listesi->setGeometry(QRect(370, 310, 341, 21));
        label_Odunc_Alinan_Kitaplar_Listesi->setFont(font);
        label_Stok = new QLabel(odunc_alma_islemleri);
        label_Stok->setObjectName("label_Stok");
        label_Stok->setGeometry(QRect(40, 420, 121, 31));
        label_Stok->setFont(font);
        label_Tum_Kitaplar = new QLabel(odunc_alma_islemleri);
        label_Tum_Kitaplar->setObjectName("label_Tum_Kitaplar");
        label_Tum_Kitaplar->setGeometry(QRect(370, 50, 301, 21));
        label_Tum_Kitaplar->setFont(font);
        label_Odunc_Alma_Islemleri = new QLabel(odunc_alma_islemleri);
        label_Odunc_Alma_Islemleri->setObjectName("label_Odunc_Alma_Islemleri");
        label_Odunc_Alma_Islemleri->setGeometry(QRect(220, 20, 261, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label_Odunc_Alma_Islemleri->setFont(font1);
        label_Odunc_Alma_Islemleri->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        lineEdit_Kitap_No = new QLineEdit(odunc_alma_islemleri);
        lineEdit_Kitap_No->setObjectName("lineEdit_Kitap_No");
        lineEdit_Kitap_No->setGeometry(QRect(170, 380, 151, 31));
        pushButton_Odunc_Al = new QPushButton(odunc_alma_islemleri);
        pushButton_Odunc_Al->setObjectName("pushButton_Odunc_Al");
        pushButton_Odunc_Al->setGeometry(QRect(130, 480, 101, 31));
        pushButton_Odunc_Al->setFont(font);
        label_Tum_Uyeler = new QLabel(odunc_alma_islemleri);
        label_Tum_Uyeler->setObjectName("label_Tum_Uyeler");
        label_Tum_Uyeler->setGeometry(QRect(40, 50, 201, 21));
        label_Tum_Uyeler->setFont(font);
        label_Kitap_No = new QLabel(odunc_alma_islemleri);
        label_Kitap_No->setObjectName("label_Kitap_No");
        label_Kitap_No->setGeometry(QRect(40, 380, 81, 31));
        label_Kitap_No->setFont(font);
        tableView_Tum_Kitaplar = new QTableView(odunc_alma_islemleri);
        tableView_Tum_Kitaplar->setObjectName("tableView_Tum_Kitaplar");
        tableView_Tum_Kitaplar->setGeometry(QRect(370, 80, 291, 221));
        dateEdit_Odunc_Alma_Tarihi = new QDateEdit(odunc_alma_islemleri);
        dateEdit_Odunc_Alma_Tarihi->setObjectName("dateEdit_Odunc_Alma_Tarihi");
        dateEdit_Odunc_Alma_Tarihi->setGeometry(QRect(170, 420, 151, 31));
        dateEdit_Odunc_Alma_Tarihi->setDateTime(QDateTime(QDate(2024, 6, 10), QTime(15, 0, 0)));
        dateEdit_Odunc_Alma_Tarihi->setMinimumDateTime(QDateTime(QDate(1999, 12, 31), QTime(14, 0, 0)));

        retranslateUi(odunc_alma_islemleri);

        QMetaObject::connectSlotsByName(odunc_alma_islemleri);
    } // setupUi

    void retranslateUi(QDialog *odunc_alma_islemleri)
    {
        odunc_alma_islemleri->setWindowTitle(QCoreApplication::translate("odunc_alma_islemleri", "Dialog", nullptr));
        label_Uye_No->setText(QCoreApplication::translate("odunc_alma_islemleri", "\303\234ye No:", nullptr));
        label_Odunc_Alinan_Kitaplar_Listesi->setText(QCoreApplication::translate("odunc_alma_islemleri", "\303\226d\303\274n\303\247 Al\304\261nan Kitaplar Listesi", nullptr));
        label_Stok->setText(QCoreApplication::translate("odunc_alma_islemleri", "\303\226d\303\274n\303\247 Alma Tarihi:", nullptr));
        label_Tum_Kitaplar->setText(QCoreApplication::translate("odunc_alma_islemleri", "T\303\274m Kitaplar", nullptr));
        label_Odunc_Alma_Islemleri->setText(QCoreApplication::translate("odunc_alma_islemleri", "\303\226D\303\234N\303\207 ALMA \304\260\305\236LEMLER\304\260", nullptr));
        pushButton_Odunc_Al->setText(QCoreApplication::translate("odunc_alma_islemleri", "\303\226d\303\274n\303\247 Al", nullptr));
        label_Tum_Uyeler->setText(QCoreApplication::translate("odunc_alma_islemleri", "T\303\274m \303\234yeler", nullptr));
        label_Kitap_No->setText(QCoreApplication::translate("odunc_alma_islemleri", "Kitap No:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class odunc_alma_islemleri: public Ui_odunc_alma_islemleri {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ODUNC_ALMA_ISLEMLERI_H
