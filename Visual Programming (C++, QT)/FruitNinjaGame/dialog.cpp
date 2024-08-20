//METEHAN AYHAN

//Extra Ozellik:  oyunun basinda ve sonunda kullaniciya bilgilendirici yazilar cikiyor.. bir de son 10 saniyede gorsel degisiyor..
//konumlar dosyadan okunuyor ve sonuclar dosyaya yazdiriliyor.. ayrica y=100'den basliyor..
//sonuclar.txt dosyasi build icinde yer aliyor.. build de proje klasorunun icinde bulunuyor galiba yeni guncellemeyle o sekilde degisti.. resource icine koydugumda hata veriyordu cunku..
//kacirilan karpuz sayisi dialog ekranina bazen gec yazdiriliyor sebebini bilemedim.. ama son ekranda hepsi dogru yaziliyor.. onun disinda eksiksiz calisiyor..

#include "dialog.h"
#include "ui_dialog.h"
#include <QWidget>
#include "oyun.h"


//Yapici metod..
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this -> setFixedSize(1350, 750); //ekrani 1350-750 boyutlarinda aciyoruz...
    //uygulama buradan baslayacak oncelikle arka plan resmini tum pencereye yayiyoruz.
    ui->back->setStyleSheet("QWidget{background-image: url(:/images/images/back.jpg);");
    //ve sonra karpuz sayacini baslatiyoruz..
    karpuz_sayaci();
    konum_oku();
    uyari();


}


Dialog::~Dialog()
{
    delete ui;
}

//baslangicta kesilen ve kacirilan 0 olmalı..
int kesilenKarpuz=0;
int kacirilanKarpuz=0;


//ZAMANLAMA FONKSİYONU
void Dialog::karpuz_sayaci()
{
    QTimer *karpuzSayac = new QTimer(this);
    connect(karpuzSayac, &QTimer::timeout, this, &Dialog::karpuz_olustur);
    // Saniyede 1 tane karpuz olusturulacak..
    karpuzSayac->start(1000);

    QTimer *oyunSuresi= new QTimer(this);
    connect(oyunSuresi, &QTimer::timeout, this, &Dialog::init);
    oyunSuresi->start(1000);

    QTimer *uyari= new QTimer(this);
    connect(uyari, &QTimer::timeout, this, &Dialog::uyari);
    uyari->start(100);
}

int maximumSkor;
int oyunSuresi=31;

//x ve y degerlerini kaydetmek icin listeler olusturuyoruz..
QVector<int> xDegerleri;
QVector<int> yDegerleri;

//KONUM OKUMA FONKSİYONU
void Dialog::konum_oku()
{
    QFile konumOku("konumlar.txt");
    if (!konumOku.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Hata!", konumOku.errorString());
        return;
    }

    QTextStream KonumOku(&konumOku);

    QString line;
    while (!KonumOku.atEnd()) {
        line = KonumOku.readLine();
        QStringList list = line.split(" ");
        if (list.size() == 2) {
            int x = list.at(0).toInt();
            int y = list.at(1).toInt();

            // x ve y değerlerini listelere ekleyoruz.
            xDegerleri.append(x);
            yDegerleri.append(y);

        }
    }
    konumOku.close();

}


int sayac=0;
int x,y;
//KARPUZ OLUSTURMA FONKSİYONU(SANİYEDE 1 TETİKLENECEK)
void Dialog::karpuz_olustur()
{
    //egerki sayac liste boyutunu asarsa sıfırlıyoruz ki konumlari bastan okusun...
    if (sayac < xDegerleri.size() && sayac < yDegerleri.size()) {
        int x = xDegerleri.at(sayac);
        int y = yDegerleri.at(sayac);
        karpuz *karpuzs = new karpuz(this);
        karpuzs->move(x, y); // karpuz nesnesinin konumunu veriyoruz
        karpuzs->setFixedSize(80, 80); // karpuz nesnesinin boyutunu ayarliyoruz
        karpuzs->setStyleSheet("QPushButton {image: url(:/images/images/1.png);}"); //karpuz resmi veriyoruz butona..

        //son 10 saniyede karpuzlar etliekmege donusuyor..:))
        if(oyunSuresi<11){
            karpuzs->setStyleSheet("QPushButton {image: url(:/images/images/png_3.png);}");
        }
        //karpuzun arkasını saydam yapmak icin
        karpuzs->setFlat(true);
        karpuzs->show();
        karpuzlar.append(karpuzs);
        sayac++;
    } else {
        sayac = 0;
    }


    //oynunun bittigi kisim..
    if (oyunSuresi == 0) {
        // Skorlari "skorlar.txt" dosyasina yazdiriyoruz..

        //skorlar.txt dosyasi build dosyasinin icinde bu yuzden sadece ismiyle cagiriyoruz..
        QFile skorlarDosyam("skorlar.txt");
        if (!skorlarDosyam.open(QIODevice::Append)) {
            QMessageBox::critical(this, "Hata!!!!", skorlarDosyam.errorString());
            return;
        }
        QTextStream streamNeSkorlarDosyam(&skorlarDosyam);
        streamNeSkorlarDosyam << QString::number(kesilenKarpuz) << "\n";
        skorlarDosyam.close();

        // Dosyadaki en buyuk sayiyi bulup karsilastircaz
        QFile skorOku("skorlar.txt");
        if (!skorOku.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, "Hata!", skorOku.errorString());
            return;
        }
        QTextStream streamNeSkorOku(&skorOku);
        QString string;
        maximumSkor = INT_MIN;

        while (!streamNeSkorOku.atEnd()) {
            string = streamNeSkorOku.readLine();
            maximumSkor = qMax(maximumSkor, string.toInt());
        }
        skorOku.close();

        // Maximum skoru gecip gecmeme durumuna gore if bloguna giricek..
        if (kesilenKarpuz == maximumSkor) {
            QMessageBox::information(this, "Bilgi!", "Oyun Bitti! Maksimum Skor Sizde! \n" "Kesilen Karpuz Sayısı: "+QString::number(kesilenKarpuz)+"\n" "Kaçırılan Karpuz Sayısı: "+QString::number(kacirilanKarpuz)+"\n" "Maximum Skor: "+QString::number(maximumSkor),
                                     "Ok");
        } else {
            QMessageBox::information(this, "Bilgi!", "Oyun Bitti! Maksimum Skoru Geçemediniz! \n" "Kesilen Karpuz Sayısı: "+QString::number(kesilenKarpuz)+"\n" "Kaçırılan Karpuz Sayısı: "+QString::number(kacirilanKarpuz)+"\n" "Maximum Skor: "+QString::number(maximumSkor), "Ok");
        }

        this->close();
    }


    // Oyun süresini azaltiyoruz her tetikleniste... cunku bu fonk. saniyede 1 cagiriliyor..
    oyunSuresi--;
    ui->label_sure->setText("<font color='blue'>"+QString::number(oyunSuresi));
}


//BASLATMA FONSİYONU
void Dialog::init()
{

    // Resmi ekranda konumlandiriyoruz..
    ui->back->setGeometry(0, 100, this->width(), this->height()); //Y Degerini 100 olarak ayarladik..
    foreach(karpuz *karpuz, karpuzlar){
        if(karpuz->y() > this->height()){
            //kacirilan karpuz ekrana bazen gec yazdiriliyor sebebini bilmiyorum..
            kacirilanKarpuz += 1;
            ui->kacirilan->setText("Kaçırılan Karpuz Sayısı: <font color='red'>"+QString::number(kacirilanKarpuz));
            karpuzlar.removeOne(karpuz);
            karpuz->hide();
             }

        if(karpuz->tiklandimi){
            kesilenKarpuz += 1;
            karpuzlar.removeOne(karpuz);
            ui->kesilen->setText("Kesilen Karpuz Sayısı:   <font color='green'>"+QString::number(kesilenKarpuz));
        }
    }

}


//EXTRA ÖZELLİK...
void Dialog::uyari()
{

    if (oyunSuresi > 25) {


        ui->metin->setText("FRUİT NİNJA.. \n Metehan Ayhan..");


    }
    if(oyunSuresi < 25 && oyunSuresi > 11){
        ui->metin->hide();
    }

    if (oyunSuresi == 10) {

        ui->metin->setVisible(true);
        ui->metin->setText("10 Saniyeniz Kaldı..");

    }

    if(oyunSuresi < 9 && oyunSuresi > 6){
        ui->metin->hide();
    }

    if (oyunSuresi == 5) {

        ui->metin->setVisible(true);
        ui->metin->setText("Son 5 Saniye..");

    }
    if (oyunSuresi == 0) {


        ui->metin->setText("Oyun Bittiiii...:)");

    }

    if (kesilenKarpuz == 10) {


        ui->metin_2->setText("10 Karpuz kestiniz tebrikler.. ");

    }

    if (kesilenKarpuz >= 12) {

        ui->metin_2->hide();


    }
}



