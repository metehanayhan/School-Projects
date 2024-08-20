//METEHAN AYHAN

#ifndef DIALOG_H
#define DIALOG_H

#include "oyun.h"
#include <QDialog>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <QtGlobal>
#include <QFile>
#include <QStringList>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void karpuz_sayaci();
    void karpuz_olustur();
    void konum_oku();
    void init();
    void uyari();


private:
    Ui::Dialog *ui;
    QList<karpuz*>karpuzlar;
};


#endif
