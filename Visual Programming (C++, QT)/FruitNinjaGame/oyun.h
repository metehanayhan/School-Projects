//METEHAN AYHAN

#ifndef OYUN_H
#define OYUN_H

#include <QPushButton>
#include <QTimer>

namespace Ui {
class karpuz;
}

class karpuz : public QPushButton
{
    Q_OBJECT

public:
    karpuz(QWidget *parent = 0);

    bool tiklandimi;

    QTimer *sayac;

public slots:
    void karpuzu_kes();

    void karpuzu_gizle();

    void buyukluk_yeredusme();

};

#endif // OYUN_H
