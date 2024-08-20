//METEHAN AYHAN

#include "oyun.h"
#include <ui_dialog.h>

karpuz::karpuz(QWidget *parrent):QPushButton(parrent)
{
    //tiklandimi adinda boolean degisken olusutup basta false olarak ayarladim..
    tiklandimi=false;

    //tiklaninca karpuzukes fonksiyonu tetiklenicek..
    connect(this, &QPushButton::clicked, this, &karpuz::karpuzu_kes);

    sayac = new QTimer(this);
    connect(sayac, &QTimer::timeout, this, &karpuz::buyukluk_yeredusme);
    // Karpuzlarin yere dusus hizini ayarliyoruz..
    sayac->start(10);
}

// karpuz kesildikten sonra ekrandan kayboluyor..
void karpuz::karpuzu_gizle()
{
    this->hide();
}


//KARPUZ KESME FONKSİYONU
void karpuz::karpuzu_kes()
{
    tiklandimi = !tiklandimi;
    QTimer *karpuzKes = new QTimer(this);

    connect(karpuzKes, &QTimer::timeout, this, &karpuz::karpuzu_gizle);

    this->setStyleSheet("QPushButton { image: url(:/images/images/2.png)}");
    this->setFlat(true);

    // Karpuz kesildikten ne kadar sure sonra ekrandan ayrilacagini AYARLADİK..
    karpuzKes->start(600);
}


void karpuz::buyukluk_yeredusme()
{
    if(!tiklandimi){
        // Karpuzlarin yere dusus koordinatlarini (this->x(), this->y()+1) olarak belirledik..
        this->setGeometry(this->x(), this->y()+1, 80, 80);

    }

}

