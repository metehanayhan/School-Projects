// METEHAN AYHAN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // INT_MAX icin(sonsuz)

/*Odevde dijkstra algoritmasinin negatif agirlikli degerlerde yanlis sonuc vermesi gösterilmesi isteniyordu.. zip dosyasinda gelen graf.txt de negatif degerler parantez icine alinmis halde..
2147483647  olarak gozüken agirlik degeri max int degerini yani sonsuzu temsil ediyor.. */
//BASLANGIC DUGUMU : 0

// Graf yapisinda en fazla kac dugum ve kenar olabilecegini belirleyen sabit
#define MAX_DUGUMLER 100
#define SINIRSIZ INT_MAX // Sonsuz degeri INT_MAX olarak tanýmladik

// Kenar yapisi..
typedef struct
{
    int baslangic, bitis, agirlik;
} Kenar;

// Graf yapýsý, dugumler ve kenarlar listesi..
typedef struct
{
    int numDugumler; // Toplam dugum sayýsý
    int numKenarlar; // Toplam kenar sayýsý
    Kenar kenarlar[MAX_DUGUMLER * MAX_DUGUMLER]; // Kenar listesi
} Graf;

// Graf yapýsýný dosyadan okuyan fonksiyon..
void grafOkuDosyadan(Graf *g, const char *dosyaAdi)
{
    FILE *dosya = fopen(dosyaAdi, "r"); // Dosyayý okuma modunda aciyoruz

    if (dosya == NULL)
    {
        perror("Dosya acilamadi");
        exit(EXIT_FAILURE);
    }

    fscanf(dosya, "%d\n", &g->numDugumler); // ilk satirdan dugum sayisini okuyoruz..
    g->numKenarlar = 0; // Kenar sayisini sifirliyoruz

    int baslangic, bitis, agirlik;
    char satir[256], *token;

    // Dosyadan satir satir okuyup kenarlari grafa ekleme islemi..
    while (fgets(satir, sizeof(satir), dosya))
    {
        token = strtok(satir, ","); // Virgülle ayrýlmýþ parcalar

        baslangic = atoi(token); // Baslangic dugumunu aldik

        while ((token = strtok(NULL, "-"))) // - isaretine göre parcalama
        {
            bitis = atoi(token); // Bitis dugumunu alma
            token = strtok(NULL, ","); // Virgulle ayrýlmýþ sonraki parca

            if (token[0] == '(') // Eger parantez icinde ise negatif agirlik olarak kabul ediyoruz bu seferki odevde..
            {
                agirlik = -atoi(token + 1); // Parantez icindeki sayiyi negatif olarak aldik
            }
            else // Degilse normal agirlik olarak kabul et
            {
                agirlik = atoi(token); // Parcayi sayiya cevir.. bu kisimlarda özel fonk kullandim..
            }

            // Kenari grafa ekliyoruz
            g->kenarlar[g->numKenarlar].baslangic = baslangic;
            g->kenarlar[g->numKenarlar].bitis = bitis;
            g->kenarlar[g->numKenarlar].agirlik = agirlik;
            g->numKenarlar++; // Keanr sayisi artti.
        }
    }

    fclose(dosya);
}

// Dijkstra algoritmasi ile en kisa yol hesaplama.. ama negatif degerler old. icin yanlis calisacak..
void Dijkstra(Graf *g, int kaynak)
{
    int mesafe[MAX_DUGUMLER]; // Dugumlerin mesafelerini tutan dizi
    int ziyaretEdildi[MAX_DUGUMLER]; // Ziyaret edilen dugumleri tutan dizi
    int i, j, minUzaklik, minIndex;

    // Tum dugumleri sonsuz mesafede olarak ayarliyoruz ve henüz ziyaret edilmedi olarak iþaretliyoruz..
    for (i = 0; i < g->numDugumler; i++)
    {
        mesafe[i] = SINIRSIZ;
        ziyaretEdildi[i] = 0;
    }

    // Baslangic dugumunun mesafesini 0 olarak ayarladik..
    mesafe[kaynak] = 0;

    // Tum dugumleri ziyaret edene kadar döngü calisacak.
    for (i = 0; i < g->numDugumler - 1; i++)
    {
        minUzaklik = SINIRSIZ;

        // En kucuk mesafeli ziyaret edilmemis dugum
        for (j = 0; j < g->numDugumler; j++)
            if (!ziyaretEdildi[j] && mesafe[j] <= minUzaklik)
            {
                minUzaklik = mesafe[j];
                minIndex = j;
            }

        // MinIndex dugumunu ziyaret edildi olarak isaretliyoruz.
        ziyaretEdildi[minIndex] = 1;

        for (j = 0; j < g->numKenarlar; j++)
            if (!ziyaretEdildi[j] && g->kenarlar[j].agirlik &&
                mesafe[minIndex] != SINIRSIZ &&
                mesafe[minIndex] + g->kenarlar[j].agirlik < mesafe[j])
                mesafe[j] = mesafe[minIndex] + g->kenarlar[j].agirlik;
    }

    // Sonuclari ekrana yazdiriyoruz..
    printf("----------------------------------------------------------\n");
    printf("Dijkstra Algoritmasi:\n");
    for (i = 0; i < g->numDugumler; i++)
        printf("%d -> %d: %d\n", kaynak, i, mesafe[i]);
}

// Bellman ford algoritmas. ile en kisa yol hesaplama islemi..
void BellmanFord(Graf *g, int kaynak)
{
    int mesafe[MAX_DUGUMLER]; // Dugumlerin mesafelerini tutan dizi
    int i, j;

    // Tum dugumleri sonsuz mesafede olarak ayarladik
    for (i = 0; i < g->numDugumler; i++)
        mesafe[i] = SINIRSIZ;

    // Baslangýç dugumunun mesafesini 0 olarak ayarla.
    mesafe[kaynak] = 0;

    // Tum kenarlari tekrarlayarak en kýsa yolu buluyoruz..
    for (i = 0; i < g->numDugumler - 1; i++)
        for (j = 0; j < g->numKenarlar; j++)
        {
            int baslangic = g->kenarlar[j].baslangic;
            int bitis = g->kenarlar[j].bitis;
            int agirlik = g->kenarlar[j].agirlik;

            // Eðer baslangic dugumunun mesafesi sonsuz degilse ve baslangic dugumunden bitis dugumune olan agirlik, bitis dugumunun mevcut mesafesinden daha kýsa ise, bitis dugumunun mesafesini güncelliycek
            if (mesafe[baslangic] != SINIRSIZ && mesafe[baslangic] + agirlik < mesafe[bitis])
                mesafe[bitis] = mesafe[baslangic] + agirlik;
        }

    // Sonuclarý ekrana yazdirma islemi.
    printf("----------------------------------------------------------\n");
    printf("Bellman-Ford Algoritmasi:\n");
    for (i = 0; i < g->numDugumler; i++)
        printf("%d -> %d: %d\n", kaynak, i, mesafe[i]);
        printf("----------------------------------------------------------");
}

int main()
{
    Graf g;
    grafOkuDosyadan(&g, "graf.txt"); // Grafi dosyadan okutuyoruz..

    // Dijkstra ve Bellmanford algoritmalarini cagiriyoruz..
    Dijkstra(&g, 0);
    BellmanFord(&g, 0);

    return 0;  //ve bitis...
}
