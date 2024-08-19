//METEHAN AYHAN


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ders
{
    char ad[50];
    int not;
    int kod;
};

struct Ogrenci
{
    char ad[50];
    char soyad[50];
    int numara;
    struct Ders dersler[3];     
    int ortalama[3];
};

void ortalamahesapla(struct Ogrenci *ogrenci) 
{
    int toplamort = 0;
    for (int i = 0; i < 3; i++)
    {
        toplamort += ogrenci->dersler[i].not;  //her ogrencinin 3dersini topladik
    }

    for (int i = 0; i < 3; i++)
    {
        ogrenci->ortalama[i] = toplamort / 3;   //ve bu toplamlari 3e bolup ortalamayi ogrenci struct ina attik..
    }
}

struct node    //bagli liste icin dugum yapisi olusturduk..
{
    int ortalama;          //sadece ortalama verileri tutulup siralancak..
    struct node *sonraki;
};

struct node *head = NULL; // liste baslangicta bos olmasi icin.. daha sonra doyadan okunup dolacak..
struct node *tail = NULL;

void elemanekle(int ortalama)
{
    struct node *yeni = (struct node*)malloc(sizeof(struct node));   //once eleman icin yer actik ve onu bir kutuya attik..
    yeni->ortalama = ortalama;    //parametreden gelen ort bilgisi dugumun datasina atildi.
    yeni->sonraki = NULL;          //next i simdilik en sonu gosteriyor

    if (head == NULL)         //buradan itibaren ihtimaller basliyor. eger liste bos ise bunun icine girecek
    {
        head = tail= yeni;       //bas ve son yeni elemani gosteriyor ilk ve tek eleman suan..
    }
    else if (yeni->ortalama < head->ortalama)     //sonraki eklenen eleman ort u, bastaki elemanýn ort undan kucukse onun onune yazilacak..
    {
        yeni->sonraki = head;
        head = yeni;         // head ya da tail ile islem yaparken onlarý en son hep guncellemek gerekiyor.. yoksa bagli listeyi kaybederiz.
    }
    else if (yeni->ortalama > tail->ortalama)      // burada da yeni gelen eleman en sondakinden buyukse sona yerlestircez
    {
        tail->sonraki = yeni;          //en sonu gosteren tail artik en buyuk elemani gosteriyor..
        tail = yeni;
    }
    else           //eger hicbiri deilse gezinen bir node olusturup elemanlara tek tek bakicaz..
    {
        struct node *gezinen = head;           //en bastan baslatiyoruz
        while (gezinen->sonraki != NULL && gezinen->sonraki->ortalama < yeni->ortalama)   //sona gelene ve yeni orttan daha buyugunu gorene kadar gezer..
        {
            gezinen = gezinen->sonraki;
        }
        yeni->sonraki = gezinen->sonraki;   //bulundugunda yeni, buyukten bir onceki konuma yerlesir
        gezinen->sonraki = yeni;
    }
}

void bagliListeyiYazdir(struct node *head)        //parametre olarak listenin basini gonderdik
{
    printf("----------------------------------------------------\n");
    printf("Bagli Listede Siralanmis Ogrenci Ortalamalari:\n");
    struct node *gezinen = head;      //yine bir gezici tanimladik her elemani gezip ekrana yazacak..

    while (gezinen != NULL)
    {
        printf("%d -> ", gezinen->ortalama);
        gezinen = gezinen->sonraki;    //bir sonraki node a gecti
    }
    printf("NULL\n");
}

void listele(struct Ogrenci *ogrenciler,int ogrenci_sayisi)      //listeleme fonk. normal struct konusu
{
    for(int i=0; i<ogrenci_sayisi; i++)     //silindikten sonra ogr sayisi azalacagindan direkt 3 demedik..
    {
        printf("----------------------------------------------------\n");
        printf("Ad: %s\n",(ogrenciler+i)->ad);
        printf("Soyad: %s\n",(ogrenciler+i)->soyad);
        printf("Numara: %d\n",(ogrenciler+i)->numara);
        for(int j=0; j<3; j++)
        {
            printf("%s Not: %d Kod: %d | ",((ogrenciler+i)->dersler+j)->ad,((ogrenciler+i)->dersler+j)->not, ((ogrenciler+i)->dersler+j)->kod);
        }
        printf("\n");
    }
}

void arama(struct Ogrenci *ogrenci, int kod_no)   //ders koduna gore arama fonksiyonu
{
    for(int i =0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(kod_no == ((ogrenci+i)->dersler+j)->kod)
            {
                printf("----------------------------------------------------\n");
                printf("%s %s %s Not:%d Kod:%d\n",(ogrenci+i)->ad,(ogrenci+i)->soyad, ((ogrenci+i)->dersler+j)->ad, ((ogrenci+i)->dersler+j)->not,  ((ogrenci+i)->dersler+j)->kod );
            }
        }
    }
}

void silme(struct Ogrenci ogrenciler[], int *ogrenci_sayisi, char silineceksoyad[])  // Soyada gore ogrencileri silen fonksiyon
{
    int silinecekIndex = -1; // Silinecek ogrencinin dizideki konumunu saklamak icin boyle bi deger verdik

    for (int i = 0; i < *ogrenci_sayisi; i++)
    {
        if (strcmp(ogrenciler[i].soyad, silineceksoyad) == 0)   //strcmp iki stringi karsilastirmak icin..
        {
            silinecekIndex = i;
            break;
        }
    }

    if (silinecekIndex != -1)    // Silinecek ogrenciyi bulunca..
    {
        for (int i = silinecekIndex; i < *ogrenci_sayisi - 1; i++)
        {
            ogrenciler[i] = ogrenciler[i + 1];
        }
        (*ogrenci_sayisi)--;
        printf("----------------------------------------------------\n");
        printf("Ogrenci basariyla silindi.\n");
    }
    else
    {
        printf("----------------------------------------------------\n");
        printf("Ogrenci bulunamadi.\n");
    }
}

int main()
{
    FILE *dosya = fopen("veriler.txt", "r");      //dosyayi okuma modunda actik..
    if (dosya == NULL)
    {
        printf("----------------------------------------------------\n");
        printf("Dosya acma hatasi\n");
        return 1;
    }

    struct Ogrenci ogrenciler[3];
    int ogrenci_sayisi = 0;

    int secim;
    char silineceksoyad[10];
    int kod_no;

    while (!feof(dosya))   //dosyanin sonunu gorene kadar okuyacak
    {
        struct Ogrenci *ogrenci = &ogrenciler[ogrenci_sayisi];   //yapiyi burada somutlastirdik..
        fscanf(dosya, "%s %s %d", ogrenci->ad, ogrenci->soyad, &ogrenci->numara);   //bilgileri dosyadan okuyup yapiya attik..

        for (int j = 0; j < 3; j++)
        {
            struct Ders *ders = &ogrenci->dersler[j];       //bu struct i da ayriyeten dolduruyoruz cunku ayri olarak tanimladik..
            fscanf(dosya, "%s %d %d", ders->ad, &ders->not, &ders->kod);
        }
        ogrenci_sayisi++;
    }

    ogrenci_sayisi--;   // burada bir azaltmamin sebebi dosyadan 4 ogrenci okuyo olmasi bu silme isleminde hataya sebep oluyo oyzdn burada bir azalttim..
    fclose(dosya);

    do
    {
        printf("----------------------------------------------------\n");
        printf("Menu:\n");
        printf("1. Verileri Listele\n");
        printf("2. Bagli Listede Ogrenci Ortalamalari\n");
        printf("3. Soyada Gore Sil\n");
        printf("4. Ders Koduna Gore Ara\n");
        printf("5. Cikis\n");
        printf("Seciminizi girin: ");
        scanf("%d", &secim);

        switch (secim)
        {
        case 1:
            listele(ogrenciler,ogrenci_sayisi);
            break;
        case 2:
            for (int i = 0; i <3; i++)
            {
                ortalamahesapla(&ogrenciler[i]);
                elemanekle(ogrenciler[i].ortalama[1]);
            }
            bagliListeyiYazdir(head);
            break;
        case 3:
            printf("----------------------------------------------------\n");
            printf("Silinecek ogrencinin soyadini girin: ");
            scanf("%s", silineceksoyad);
            silme(ogrenciler, &ogrenci_sayisi, silineceksoyad);
            break;

        case 4:
            printf("----------------------------------------------------\n");
            printf("Aranacak dersin kodunu girin: ");
            scanf("%d", &kod_no);
            arama(ogrenciler, kod_no);
            break;
        case 5:
            printf("----------------------------------------------------\n");
            printf("Cikis yapildi.\n");
            break;
        default:
            printf("----------------------------------------------------\n");
            printf("Gecersiz secenek!\n");
            break;
        }
    }
    while (secim != 5);

    // Bagli listedeki dugumleri temizliyoruzki program kapandiktan sonra bellekte yer kaplamasin, sikinti cikmasin..
    struct node *gezinen = head;
    while (gezinen != NULL)
    {
        struct node *temp = gezinen;
        gezinen = gezinen->sonraki;
        free(temp);
    }

    return 0;
}
