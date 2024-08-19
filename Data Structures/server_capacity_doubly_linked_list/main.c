//METEHAN AYHAN

#include <stdio.h>
#include <stdlib.h>

struct Sunucu
{
    int id_no;
    float yuk;
    int max_kapasite;
    float kalan_kapasite;
    struct Sunucu* onceki;
    struct Sunucu* sonraki;
};

struct Sunucu* bas = NULL;

// Yeni sunucu olusturma fonksiyonu.. kullanicinin basta sececegi sayi kadar dugum olusturcak..
struct Sunucu* sunucu_olustur(int id_no, int max_kapasite)
{
    struct Sunucu* yeni_sunucu = (struct Sunucu*)malloc(sizeof(struct Sunucu));
    yeni_sunucu->id_no = id_no;
    yeni_sunucu->yuk = 0;
    yeni_sunucu->max_kapasite = max_kapasite;     //kullanicidan gelen max kapasite bilgisini yeni sunucuya attik..
    yeni_sunucu->kalan_kapasite = max_kapasite;
    yeni_sunucu->onceki = NULL;
    yeni_sunucu->sonraki = NULL;
    return yeni_sunucu;
}

// Yeni sunucuyu listede gerekli yere ekleyen fonk..
void sunucu_ekle(int id_no, int max_kapasite)
{
    struct Sunucu* yeni_sunucu = sunucu_olustur(id_no, max_kapasite);
    if (bas == NULL)    //liste bos ise
    {
        bas = yeni_sunucu;
        bas->onceki = yeni_sunucu;       //cift bagli listenin oncesi sonrasi tek elemana baglandi..
        bas->sonraki = yeni_sunucu;
    }
    else
    {
        yeni_sunucu->onceki = bas->onceki;
        yeni_sunucu->sonraki = bas;                 //eger liste bos deilse  sunucu yeni sunucunun oncesine eklenecek..
        bas->onceki->sonraki = yeni_sunucu;
        bas->onceki = yeni_sunucu;
    }
}

// sunuculari kalan kapasitelerine gore siralayan fonk..
void sirala()
{
    if (bas == NULL)  //liste bos ise hicbisi yapma..
    {
        return;
    }
    struct Sunucu* sunucu = bas;
    struct Sunucu* temp;     //siralama icin gecici deisken kullaniyoruz..
    do
    {
        temp = sunucu->sonraki;
        while (temp != bas)     //listenin sonuna kadar gez.
        {
            if (temp->kalan_kapasite > sunucu->kalan_kapasite)     //sonraki sunucunun kalan kapasitesi, suanki sunucununkinden büyükse...
            {
                int temp_id_no = temp->id_no;
                float temp_yuk = temp->yuk;                                      // Sunucularýn max k. bilgilerini yer degistiriyoruz
                int temp_max_kapasite = temp->max_kapasite;
                float temp_kalan_kapasite = temp->kalan_kapasite;

                temp->id_no = sunucu->id_no;
                temp->yuk = sunucu->yuk;
                temp->max_kapasite = sunucu->max_kapasite;
                temp->kalan_kapasite = sunucu->kalan_kapasite;

                sunucu->id_no = temp_id_no;
                sunucu->yuk = temp_yuk;
                sunucu->max_kapasite = temp_max_kapasite;
                sunucu->kalan_kapasite = temp_kalan_kapasite;
            }
            temp = temp->sonraki;
        }
        sunucu = sunucu->sonraki;
    }
    while (sunucu != bas);   //sona kadar devam et
}

void uretici(float uretilen_yuk)
{
    if (bas == NULL)
    {
        printf("Sunucu bulunamadý. Once sunucu ekleyin.\n");
        return;
    }

    struct Sunucu* sunucu = bas;
    struct Sunucu* en_az_yuklu = sunucu;

    // En az yuk bulunan sunucuyu buluyoruz..
    do
    {
        if (sunucu->kalan_kapasite < en_az_yuklu->kalan_kapasite)
        {
            en_az_yuklu = sunucu;
        }
        sunucu = sunucu->sonraki;
    }
    while (sunucu != bas);

    sunucu = en_az_yuklu;

    do
    {
        if (uretilen_yuk <= sunucu->kalan_kapasite)
        {
            // uretilen yuk sunucunun kalan kapasitesinden kucuk veya esitse yuku sunucuya ekliycez ve kalan kapasiteyi guncelliycez
            sunucu->yuk += uretilen_yuk;
            sunucu->kalan_kapasite -= uretilen_yuk;
            break;
        }
        else
        {
            // Eger uretilen yuk sunucunun kalan kapasitesinden buyukse sunucuya yuk ekleyip kalan yuku hesaplatip ve bir sonraki sunucuya gecicek
            sunucu->yuk += sunucu->kalan_kapasite;
            uretilen_yuk -= sunucu->kalan_kapasite;
            sunucu->kalan_kapasite = 0;

            //bir sonraki sunucuya gec..
            sunucu = sunucu->sonraki;
        }
    }
    while (sunucu != en_az_yuklu);

    sirala(); //sunuculari kalan kapasitelerine gore siraliyoruz
    printf("Yuk en azdan baslanarak yerlestirildi, kalan kapasitelere gore en coktan aza listelendi.\n");
}


void tuketici(float harcanan_yuk)
{

    struct Sunucu* sunucu = bas;
    do
    {
        if (harcanan_yuk <= sunucu->yuk) // harcanan yuk sunucunun yukunden kucuk veya esitse yuku sunucudan cikaricaz ve kalan kapasiteyi guncelliycek..
        {
            sunucu->yuk -= harcanan_yuk;
            sunucu->kalan_kapasite += harcanan_yuk;
            break;
        }
        else    //eger harcanan daha fazlaysa yuku sunucudan çikarcaz. hepsi tuketildigi icin 0liycaz..  kapasite max a yukselcek.. ve sonrakine gec
        {
            harcanan_yuk -= sunucu->yuk;
            sunucu->yuk = 0;
            sunucu->kalan_kapasite = sunucu->max_kapasite;
            sunucu = sunucu->sonraki;
        }
    }
    while (sunucu != bas);   //listenin basina dönene kadar tekrarlicak bu islemi

    sirala();
    printf("Yuk en coktan baslanarak tuketildi, kalan kapasitelere gore en coktan aza listelendi.\n");
}

// sunucu listesini ekrana yazdýran fonk..
void listele()
{
    if (bas == NULL)
    {
        printf("Liste bos.\n");
        return;
    }
    struct Sunucu* sunucu = bas;  //bastan baslayip sona kadar yazdiriyor..
    do
    {
        printf("-------------------------------------------------------------------\n");
        printf("Sunucu ID: %d, Yuk: %.2f, Max Kapasite: %d, Kalan Kapasite: %.2f\n", sunucu->id_no, sunucu->yuk, sunucu->max_kapasite, sunucu->kalan_kapasite);
        sunucu = sunucu->sonraki;
    }
    while (sunucu != bas);
}

int main()
{
    int sunucu_sayisi;
    printf("VERI YAPILARI 2. ODEV\nMETEHAN AYHAN\n22100011024\n");
    printf("----------------------------------------------\n");
    printf("Baslangicta kac sunucu olacak: ");
    scanf("%d", &sunucu_sayisi);
    printf("----------------------------------------------\n");
    for (int i = 1; i <= sunucu_sayisi; i++)
    {
        int max_kapasite;
        printf("Sunucu %d icin max kapasite: ", i);
        scanf("%d", &max_kapasite);
        sunucu_ekle(i, max_kapasite);     //baslangicta kullanicidan bu bilgileri alip struct icine atiyoruz...
    }

    int secim;
    float uretilen_yuk = 0;         //hoca bunlari float cinsinden istemisti..
    float harcanan_yuk = 0;

    do          //menu tasalardik
    {
        printf("----------------------------------------------\n");
        printf("MENU:\n1. Uretici\n2. Tuketici\n3. Listele\n4. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim)
        {
        case 1:
            printf("----------------------------------------------\n");
            printf("Uretilecek yuk miktari: ");
            scanf("%f", &uretilen_yuk);
            uretici(uretilen_yuk);
            break;
        case 2:
            printf("----------------------------------------------\n");
            printf("Harcanacak yuk miktari: ");
            scanf("%f", &harcanan_yuk);
            tuketici(harcanan_yuk);
            break;
        case 3:
            listele();
            break;
        case 4:
            printf("----------------------------------------------\n");
            printf("Programdan cikiliyor...\n");
            break;
        default:
            printf("----------------------------------------------\n");
            printf("Gecersiz secenek!\n");
        }
    }
    while (secim != 4);

    // Bellegi temizliyip programi sonlandiriyoruz..
    struct Sunucu* sunucu = bas;
    if (bas != NULL)
    {
        do
        {
            struct Sunucu* silinecek = sunucu;
            sunucu = sunucu->sonraki;
            free(silinecek);
        }
        while (sunucu != bas);
    }

    return 0;
}

