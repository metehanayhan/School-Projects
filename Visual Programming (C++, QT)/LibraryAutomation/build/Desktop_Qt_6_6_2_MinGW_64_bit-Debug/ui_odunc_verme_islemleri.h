/********************************************************************************
** Form generated from reading UI file 'odunc_verme_islemleri.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ODUNC_VERME_ISLEMLERI_H
#define UI_ODUNC_VERME_ISLEMLERI_H

#include <QtCore/QDate>
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

class Ui_odunc_verme_islemleri
{
public:
    QPushButton *pushButton_Odunc_Kitap_Teslim_Et;
    QTableView *tableView_Teslim_Edilen_Kitaplar_Listesi;
    QLabel *label_Teslim_Edilen_Kitaplar_Listesi;
    QTableView *tableView_Odunc_Alinan_Kitaplar_Listesi;
    QLineEdit *lineEdit_Uye_No;
    QLabel *label_Odunc_Alinan_Kitaplar_Listesi;
    QLabel *label_Uye_No;
    QLabel *label_Odunc_Teslim_Etme_Islemleri;
    QLineEdit *lineEdit_Kitap_No;
    QLabel *label_Kitap_No;
    QLabel *label_Odunc_Verme_Tarihi;
    QDateEdit *dateEdit_Odunc_Verme_Tarihi;

    void setupUi(QDialog *odunc_verme_islemleri)
    {
        if (odunc_verme_islemleri->objectName().isEmpty())
            odunc_verme_islemleri->setObjectName("odunc_verme_islemleri");
        odunc_verme_islemleri->resize(978, 309);
        pushButton_Odunc_Kitap_Teslim_Et = new QPushButton(odunc_verme_islemleri);
        pushButton_Odunc_Kitap_Teslim_Et->setObjectName("pushButton_Odunc_Kitap_Teslim_Et");
        pushButton_Odunc_Kitap_Teslim_Et->setGeometry(QRect(430, 260, 101, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        pushButton_Odunc_Kitap_Teslim_Et->setFont(font);
        tableView_Teslim_Edilen_Kitaplar_Listesi = new QTableView(odunc_verme_islemleri);
        tableView_Teslim_Edilen_Kitaplar_Listesi->setObjectName("tableView_Teslim_Edilen_Kitaplar_Listesi");
        tableView_Teslim_Edilen_Kitaplar_Listesi->setGeometry(QRect(660, 70, 291, 221));
        label_Teslim_Edilen_Kitaplar_Listesi = new QLabel(odunc_verme_islemleri);
        label_Teslim_Edilen_Kitaplar_Listesi->setObjectName("label_Teslim_Edilen_Kitaplar_Listesi");
        label_Teslim_Edilen_Kitaplar_Listesi->setGeometry(QRect(660, 40, 301, 21));
        label_Teslim_Edilen_Kitaplar_Listesi->setFont(font);
        tableView_Odunc_Alinan_Kitaplar_Listesi = new QTableView(odunc_verme_islemleri);
        tableView_Odunc_Alinan_Kitaplar_Listesi->setObjectName("tableView_Odunc_Alinan_Kitaplar_Listesi");
        tableView_Odunc_Alinan_Kitaplar_Listesi->setGeometry(QRect(10, 70, 291, 221));
        lineEdit_Uye_No = new QLineEdit(odunc_verme_islemleri);
        lineEdit_Uye_No->setObjectName("lineEdit_Uye_No");
        lineEdit_Uye_No->setEnabled(false);
        lineEdit_Uye_No->setGeometry(QRect(470, 110, 151, 31));
        label_Odunc_Alinan_Kitaplar_Listesi = new QLabel(odunc_verme_islemleri);
        label_Odunc_Alinan_Kitaplar_Listesi->setObjectName("label_Odunc_Alinan_Kitaplar_Listesi");
        label_Odunc_Alinan_Kitaplar_Listesi->setGeometry(QRect(10, 40, 341, 21));
        label_Odunc_Alinan_Kitaplar_Listesi->setFont(font);
        label_Uye_No = new QLabel(odunc_verme_islemleri);
        label_Uye_No->setObjectName("label_Uye_No");
        label_Uye_No->setGeometry(QRect(320, 110, 111, 31));
        label_Uye_No->setFont(font);
        label_Odunc_Teslim_Etme_Islemleri = new QLabel(odunc_verme_islemleri);
        label_Odunc_Teslim_Etme_Islemleri->setObjectName("label_Odunc_Teslim_Etme_Islemleri");
        label_Odunc_Teslim_Etme_Islemleri->setGeometry(QRect(310, 10, 331, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label_Odunc_Teslim_Etme_Islemleri->setFont(font1);
        label_Odunc_Teslim_Etme_Islemleri->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        lineEdit_Kitap_No = new QLineEdit(odunc_verme_islemleri);
        lineEdit_Kitap_No->setObjectName("lineEdit_Kitap_No");
        lineEdit_Kitap_No->setEnabled(false);
        lineEdit_Kitap_No->setGeometry(QRect(470, 160, 151, 31));
        label_Kitap_No = new QLabel(odunc_verme_islemleri);
        label_Kitap_No->setObjectName("label_Kitap_No");
        label_Kitap_No->setGeometry(QRect(320, 160, 101, 31));
        label_Kitap_No->setFont(font);
        label_Odunc_Verme_Tarihi = new QLabel(odunc_verme_islemleri);
        label_Odunc_Verme_Tarihi->setObjectName("label_Odunc_Verme_Tarihi");
        label_Odunc_Verme_Tarihi->setGeometry(QRect(320, 210, 141, 31));
        label_Odunc_Verme_Tarihi->setFont(font);
        dateEdit_Odunc_Verme_Tarihi = new QDateEdit(odunc_verme_islemleri);
        dateEdit_Odunc_Verme_Tarihi->setObjectName("dateEdit_Odunc_Verme_Tarihi");
        dateEdit_Odunc_Verme_Tarihi->setGeometry(QRect(470, 210, 151, 31));
        dateEdit_Odunc_Verme_Tarihi->setDateTime(QDateTime(QDate(2024, 6, 10), QTime(9, 0, 0)));
        dateEdit_Odunc_Verme_Tarihi->setMinimumDateTime(QDateTime(QDate(1999, 12, 31), QTime(8, 0, 0)));
        dateEdit_Odunc_Verme_Tarihi->setDate(QDate(2024, 6, 10));

        retranslateUi(odunc_verme_islemleri);

        QMetaObject::connectSlotsByName(odunc_verme_islemleri);
    } // setupUi

    void retranslateUi(QDialog *odunc_verme_islemleri)
    {
        odunc_verme_islemleri->setWindowTitle(QCoreApplication::translate("odunc_verme_islemleri", "Dialog", nullptr));
        pushButton_Odunc_Kitap_Teslim_Et->setText(QCoreApplication::translate("odunc_verme_islemleri", "\303\226d\303\274nc\303\274 Ver", nullptr));
        label_Teslim_Edilen_Kitaplar_Listesi->setText(QCoreApplication::translate("odunc_verme_islemleri", "Teslim Edilen Kitaplar Listesi", nullptr));
        lineEdit_Uye_No->setText(QString());
        label_Odunc_Alinan_Kitaplar_Listesi->setText(QCoreApplication::translate("odunc_verme_islemleri", "\303\226d\303\274n\303\247 Al\304\261nan Kitaplar Listesi", nullptr));
        label_Uye_No->setText(QCoreApplication::translate("odunc_verme_islemleri", "\303\234ye No:", nullptr));
        label_Odunc_Teslim_Etme_Islemleri->setText(QCoreApplication::translate("odunc_verme_islemleri", "\303\226D\303\234N\303\207 TESL\304\260M ETME \304\260\305\236LEMLER\304\260", nullptr));
        lineEdit_Kitap_No->setText(QString());
        label_Kitap_No->setText(QCoreApplication::translate("odunc_verme_islemleri", "Kitap No:", nullptr));
        label_Odunc_Verme_Tarihi->setText(QCoreApplication::translate("odunc_verme_islemleri", "\303\226d\303\274n\303\247 Verme Tarihi:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class odunc_verme_islemleri: public Ui_odunc_verme_islemleri {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ODUNC_VERME_ISLEMLERI_H
