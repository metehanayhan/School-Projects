/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *centralwidget;
    QLabel *back;
    QLabel *label_sure;
    QLabel *label_kacirilan;
    QLabel *label_kesilen;
    QLabel *labelTime;
    QLabel *kacirilan;
    QLabel *kesilen;
    QLabel *metin;
    QLabel *metin_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(757, 592);
        centralwidget = new QWidget(Dialog);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 20, 1350, 750));
        back = new QLabel(centralwidget);
        back->setObjectName("back");
        back->setGeometry(QRect(0, 90, 711, 481));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Black")});
        back->setFont(font);
        back->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/back.png);"));
        back->setPixmap(QPixmap(QString::fromUtf8(":/images/images/back.jpg")));
        back->setScaledContents(true);
        label_sure = new QLabel(centralwidget);
        label_sure->setObjectName("label_sure");
        label_sure->setGeometry(QRect(70, 30, 51, 21));
        label_kacirilan = new QLabel(centralwidget);
        label_kacirilan->setObjectName("label_kacirilan");
        label_kacirilan->setGeometry(QRect(680, 10, 49, 16));
        label_kesilen = new QLabel(centralwidget);
        label_kesilen->setObjectName("label_kesilen");
        label_kesilen->setGeometry(QRect(670, 50, 49, 16));
        labelTime = new QLabel(centralwidget);
        labelTime->setObjectName("labelTime");
        labelTime->setGeometry(QRect(30, 30, 42, 18));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(false);
        labelTime->setFont(font1);
        kacirilan = new QLabel(centralwidget);
        kacirilan->setObjectName("kacirilan");
        kacirilan->setGeometry(QRect(530, 10, 152, 18));
        kacirilan->setFont(font1);
        kesilen = new QLabel(centralwidget);
        kesilen->setObjectName("kesilen");
        kesilen->setGeometry(QRect(530, 50, 150, 18));
        kesilen->setFont(font1);
        metin = new QLabel(centralwidget);
        metin->setObjectName("metin");
        metin->setGeometry(QRect(0, 90, 541, 211));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setItalic(true);
        metin->setFont(font2);
        metin_2 = new QLabel(centralwidget);
        metin_2->setObjectName("metin_2");
        metin_2->setGeometry(QRect(570, 50, 541, 211));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setItalic(true);
        metin_2->setFont(font3);
        metin_2->setCursor(QCursor(Qt::ArrowCursor));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        back->setText(QString());
        label_sure->setText(QString());
        label_kacirilan->setText(QString());
        label_kesilen->setText(QString());
        labelTime->setText(QCoreApplication::translate("Dialog", "S\303\274re: ", nullptr));
        kacirilan->setText(QCoreApplication::translate("Dialog", "Ka\303\247\304\261r\304\261lan Karpuz Say\304\261s\304\261: ", nullptr));
        kesilen->setText(QCoreApplication::translate("Dialog", "Kesilen Karpuz Say\304\261s\304\261:   ", nullptr));
        metin->setText(QString());
        metin_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
