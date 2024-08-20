/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_Kutuphane_Otomasyonu;
    QPushButton *pushButton_Uye_Islemleri;
    QPushButton *pushbutton_Kitap_Islemleri;
    QPushButton *pushbutton_Odunc_Alma_Islemleri;
    QGraphicsView *graphicsView_1;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView_3;
    QGraphicsView *graphicsView_4;
    QPushButton *pushbutton_Odunc_Verme_Islemleri;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(911, 415);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_Kutuphane_Otomasyonu = new QLabel(centralwidget);
        label_Kutuphane_Otomasyonu->setObjectName("label_Kutuphane_Otomasyonu");
        label_Kutuphane_Otomasyonu->setGeometry(QRect(180, 30, 581, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        label_Kutuphane_Otomasyonu->setFont(font);
        label_Kutuphane_Otomasyonu->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 18pt \"Arial\";"));
        pushButton_Uye_Islemleri = new QPushButton(centralwidget);
        pushButton_Uye_Islemleri->setObjectName("pushButton_Uye_Islemleri");
        pushButton_Uye_Islemleri->setGeometry(QRect(60, 300, 151, 41));
        pushButton_Uye_Islemleri->setMaximumSize(QSize(161, 16777215));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        pushButton_Uye_Islemleri->setFont(font1);
        pushButton_Uye_Islemleri->setStyleSheet(QString::fromUtf8(""));
        pushbutton_Kitap_Islemleri = new QPushButton(centralwidget);
        pushbutton_Kitap_Islemleri->setObjectName("pushbutton_Kitap_Islemleri");
        pushbutton_Kitap_Islemleri->setGeometry(QRect(270, 300, 151, 41));
        pushbutton_Kitap_Islemleri->setFont(font1);
        pushbutton_Kitap_Islemleri->setStyleSheet(QString::fromUtf8(""));
        pushbutton_Odunc_Alma_Islemleri = new QPushButton(centralwidget);
        pushbutton_Odunc_Alma_Islemleri->setObjectName("pushbutton_Odunc_Alma_Islemleri");
        pushbutton_Odunc_Alma_Islemleri->setGeometry(QRect(460, 300, 191, 41));
        pushbutton_Odunc_Alma_Islemleri->setFont(font1);
        pushbutton_Odunc_Alma_Islemleri->setStyleSheet(QString::fromUtf8(""));
        graphicsView_1 = new QGraphicsView(centralwidget);
        graphicsView_1->setObjectName("graphicsView_1");
        graphicsView_1->setGeometry(QRect(50, 90, 171, 181));
        graphicsView_1->setStyleSheet(QString::fromUtf8("background-image: url(:/resimler/images/user.jpg);\n"
"border-image: url(:/resimler/images/user.jpg);"));
        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName("graphicsView_2");
        graphicsView_2->setGeometry(QRect(270, 90, 161, 181));
        graphicsView_2->setStyleSheet(QString::fromUtf8("background-image: url(:/resimler/images/book.jpg);\n"
"border-image: url(:/resimler/images/book.jpg);"));
        graphicsView_3 = new QGraphicsView(centralwidget);
        graphicsView_3->setObjectName("graphicsView_3");
        graphicsView_3->setGeometry(QRect(480, 90, 161, 181));
        graphicsView_3->setStyleSheet(QString::fromUtf8("background-image: url(:/resimler/images/odunc_1.jpg);"));
        graphicsView_4 = new QGraphicsView(centralwidget);
        graphicsView_4->setObjectName("graphicsView_4");
        graphicsView_4->setGeometry(QRect(700, 90, 161, 181));
        graphicsView_4->setStyleSheet(QString::fromUtf8("background-image: url(:/resimler/images/odunc_2.jpg);"));
        pushbutton_Odunc_Verme_Islemleri = new QPushButton(centralwidget);
        pushbutton_Odunc_Verme_Islemleri->setObjectName("pushbutton_Odunc_Verme_Islemleri");
        pushbutton_Odunc_Verme_Islemleri->setGeometry(QRect(670, 300, 231, 41));
        pushbutton_Odunc_Verme_Islemleri->setFont(font1);
        pushbutton_Odunc_Verme_Islemleri->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 911, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Ana Men\303\274", nullptr));
        label_Kutuphane_Otomasyonu->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">K\303\234T\303\234PHANE OTOMASYONUNA HO\305\236GELD\304\260N\304\260Z!</span></p></body></html>", nullptr));
        pushButton_Uye_Islemleri->setText(QCoreApplication::translate("MainWindow", "\303\234ye \304\260\305\237lemleri", nullptr));
        pushbutton_Kitap_Islemleri->setText(QCoreApplication::translate("MainWindow", "Kitap \304\260\305\237lemleri", nullptr));
        pushbutton_Odunc_Alma_Islemleri->setText(QCoreApplication::translate("MainWindow", "\303\226d\303\274n\303\247 Alma \304\260\305\237lemleri", nullptr));
        pushbutton_Odunc_Verme_Islemleri->setText(QCoreApplication::translate("MainWindow", "\303\226d\303\274n\303\247 Teslim Etme \304\260\305\237lemleri", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
