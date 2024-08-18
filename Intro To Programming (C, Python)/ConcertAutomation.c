
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char sanatci_adi[10];
    char sanatci_soyadi[10];
} sanatci;


typedef struct
{
    char konser_adi[10];
    char tarih[10];
    int kontenjan;
    int bilet_fiyati;
    sanatci sanatci;
} Konser;


typedef struct
{
    Konser *konserler;
    int eleman_sayisi;
} Veri;




void konserEkle(Veri *veri, Konser konser)
{
    veri->eleman_sayisi++;
    veri->konserler = (Konser*) realloc(veri->konserler, veri->eleman_sayisi * sizeof(Konser));
    veri->konserler[veri->eleman_sayisi - 1] = konser;
}


void konserleriListele(Veri *veri)
{
    printf("Konser Listesi:\n");
    for (int i = 0; i < veri->eleman_sayisi; i++)
    {
        printf("%d. Konser: %s\nSanatci Adi:%s\nSanatci Soyadi:%s\nTarih:%s -\nKontenjan: %d - \nBilet Fiyati: %d\n", i + 1, veri->konserler[i].konser_adi, veri->konserler[i].sanatci.sanatci_adi,veri->konserler[i].sanatci.sanatci_soyadi, veri->konserler[i].tarih, veri->konserler[i].kontenjan, veri->konserler[i].bilet_fiyati);
    }
}


void konserGuncelle(Veri *veri, int konserno)
{
    printf("Yeni konser adi: ");
    scanf("%s", veri->konserler[konserno].konser_adi);
    printf("Yeni sanatci adi:");
    scanf("%s", veri->konserler[konserno].sanatci.sanatci_adi);
    printf("Yeni sanatci soyadi:");
    scanf("%s", veri->konserler[konserno].sanatci.sanatci_soyadi);
    printf("Yeni tarih: ");
    scanf("%s", veri->konserler[konserno].tarih);
    printf("Yeni kontenjan: ");
    scanf("%d", &veri->konserler[konserno].kontenjan);
    printf("Yeni bilet fiyati: ");
    scanf("%d", &veri->konserler[konserno].bilet_fiyati);
}


void konserSil(Veri *veri, int konserno)
{
    for (int i = konserno; i < veri->eleman_sayisi - 1; i++)
    {
        veri->konserler[i] = veri->konserler[i + 1];
    }
    veri->eleman_sayisi--;
    veri->konserler = (Konser*) realloc(veri->konserler, veri->eleman_sayisi * sizeof(Konser));
}


void konserleriTariheGoreSirala(Veri *veri)
{
    for (int i = 0; i < veri->eleman_sayisi - 1; i++)
    {
        for (int j = i + 1; j < veri->eleman_sayisi; j++)
        {
            if (strcmp(veri->konserler[i].tarih, veri->konserler[j].tarih) > 0)
            {
                Konser temp = veri->konserler[i];
                veri->konserler[i] = veri->konserler[j];
                veri->konserler[j] = temp;
            }
        }
    }
}


void konserleriFiyataGoreSirala(Veri *veri)
{
    for (int i = 0; i < veri->eleman_sayisi - 1; i++)
    {
        for (int j = i + 1; j < veri->eleman_sayisi; j++)
        {
            if (veri->konserler[i].bilet_fiyati > veri->konserler[j].bilet_fiyati)
            {
                Konser temp = veri->konserler[i];
                veri->konserler[i] = veri->konserler[j];
                veri->konserler[j] = temp;
            }
        }
    }
}

int main()
{

    Veri *veri = (Veri*) calloc(1,sizeof(Veri));
    veri->eleman_sayisi = 0;
    int secim,tus,konserno;
    int i=0;
    Konser konser;

    do
    {
        printf("\nKonser Otomasyonu Menusu\n");
        printf("1. Konser Ekle\n");
        printf("2. Konserleri Listele\n");
        printf("3. Konser Guncelle\n");
        printf("4. Konser Sil\n");
        printf("5. Konserleri Tarihe Gore Sirala\n");
        printf("6. Konserleri Fiyata Gore Sirala\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);
        switch(secim)
        {
        case  1:
            printf("Konser adi:");
            scanf("%s", konser.konser_adi);
            printf("Sanatci adi:");
            scanf("%s", konser.sanatci.sanatci_adi);
            printf("Sanatci soyadi:");
            scanf("%s", konser.sanatci.sanatci_soyadi);
            printf("Tarih:");
            scanf("%s", konser.tarih);
            printf("Kontenjan:");
            scanf("%d", &konser.kontenjan);
            printf("Bilet fiyati:");
            scanf("%d", &konser.bilet_fiyati);
            konserEkle(veri, konser);
            printf("Konser basariyla eklendi.\n");

            break;
        case  2:
            konserleriListele(veri);
            break;
        case 3 :

            printf("Guncellenecek konserin numarasi: ");
            scanf("%d", &konserno);
            konserno--;
            if (konserno >= 0 && konserno < veri->eleman_sayisi)
            {
                konserGuncelle(veri, konserno);
                printf("Konser basariyla guncellendi.\n");
            }
            else
            {
                printf("Gecersiz konser numarasi.\n");
            }
            break;
        case  4:

            printf("Silinecek konserin numarasi: ");
            scanf("%d", &konserno);
            konserno--;
            if (konserno >= 0 && konserno < veri->eleman_sayisi)
            {
                konserSil(veri, konserno);
                printf("Konser basariyla silindi.\n");
            }
            else
            {
                printf("Gecersiz konser numarasi.\n");
            }
            break;
        case  5:
            konserleriTariheGoreSirala(veri);
            printf("Konserler basariyla tarihe gore siralandi.\n");
            break;
        case  6:
            konserleriFiyataGoreSirala(veri);
            printf("Konserler basariyla fiyata gore siralandi.\n");
            break;
        default:
            printf("Lutfen 1-6 arasinda sayi giriniz!");
        }
        i++;
        printf("cikmak icin 0'i menuye donmek icin bir sayi tuslayin.");
        scanf("%d",&tus);
    }
    while(tus!=0);
    return 0;

    return 0;
}
