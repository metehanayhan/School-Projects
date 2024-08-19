//METEHAN AYHAN
//VERI YAPILARI ODEV 4

#include <stdio.h>
#include <stdlib.h>

//AGAC DUGUMU YAPISI         //isim no verileri ve sag sol isaretcilerini iceriyor..
struct node
{
    int no;
    char ad[10];
    struct node* sol;
    struct node* sag;
    int tekrarSayisi;
};

// TEKRAR SAYISI FAZLA OLANLARI LISTELEME FONKSIYONU
void tekrarSayisiFazlaOlanlariListele(struct node* root)
{
    if (root != NULL)
    {
        tekrarSayisiFazlaOlanlariListele(root->sol);        //sol kisim geziliyor

        if (root->tekrarSayisi > 1)
        {
            printf("Isim: %s, Tekrar Sayisi: %d\n", root->ad, root->tekrarSayisi);      //yazdiriliyor..
        }

        tekrarSayisiFazlaOlanlariListele(root->sag);        //sag kisim geziliyor.
    }
}

// ROOT OLUSTURMA FONKSIYONU
struct node* kokOlustur(int no, char ad[])
{
    struct node* root = (struct node*)malloc(sizeof(struct node));    //bellekten yer ayrildi.
    strcpy(root->ad, ad);
    root->no = no;
    root->sag = root->sol = NULL;        //baslangicta sag sol bos yapiliyor daha sonra eklenecek..
    root->tekrarSayisi = 1;   //ilk olustugunda1 olcak
    return root;
}

//EKLEME FONKSIYONU
struct node* ekle(struct node* root, int no, char ad[])
{
    if (root != NULL)       //root bos deilse eklenecek bos ise kok olusturulacak..
    {
        if (no < root->no)                         //kucuk no lu dugumler sola ekleniyor.
            root->sol = ekle(root->sol, no, ad);
        else
            root->sag = ekle(root->sag, no, ad);   //buyukler ise saga
        if(root->no==no)
        {
            root->tekrarSayisi++;
        }
    }
    else
    {
        root = kokOlustur(no, ad);    //bos ise kok olusturuluyor..
    }
    return root;
}


// DOSYADAN VERI OKUMA VE AGACA EKLEME FONKSIYONU
struct node *veriOkuVeEkle(struct node *root, const char *dosyaAdi)
{
    FILE *dosya = fopen(dosyaAdi, "r");      //dosya okunup tum veriler agaca kaydedilcek sonra ordan islemleri yapacagiz..
    if (dosya == NULL)
    {
        printf("Dosya acilamadi.\n");
        exit(1);
    }

    int no;
    char ad[10];

    while (fscanf(dosya, "%s %d", ad, &no) != EOF)
    {
        root = ekle(root, no, ad);    //agaca ekleme kismi..
    }

    fclose(dosya);

    return root;
}


//AGACIN YUKSEKLIGINI BULAN FONKSIYON
int yukseklik(struct node* root)
{
    if(root==0)         //root bos ise yukseklik -1 olur
        return -1;
    else
    {
        int sag,sol;
        sag=yukseklik(root->sag);     //sag ve solun en altina inip o veriyi tutuyoruz ve hangisi daha buyukse
        sol= yukseklik(root->sol);
        if(sag>sol)
        {
            return sag+1;
        }
        else
        {
            return sol+1;
        }
    }
}

//SILME FONKSIYONU
struct node* silme(struct node* root, char ad[])       //ayni addakilerin hepsini silecekk..
{
    if (root == NULL)
    {
        return NULL;
    }

    // Ada eslesiyorsa bu dugumu silip ve sol ve sag alt agaclarda aramaya devam edicez
    if (strcmp(root->ad, ad) == 0)
    {
        struct node* sol = root->sol;
        struct node* sag = root->sag;
        free(root);

        // Sol ve sag alt agaclarda da ayni ada sahip dugumleri siliyoruz
        root = silme(sol, ad);
        root = silme(sag, ad);

        return root;
    }
    else
    {
        // Ada eslesmiyorsa sol ve sag alt agaclarda aramaya devam ediyoruz...
        root->sol = silme(root->sol, ad);
        root->sag = silme(root->sag, ad);
        return root;
    }
}


//ELEMAN SAYISI BULAN FONKSIYON    ortalama bulmak icin yapiyoruz..
int say(struct node* root)
{
    if(root==NULL)    //bos ise zaten eleman sayisi 0 olacak
    {
        return 0;
    }
    else
    {
        return say(root->sol) + say(root->sag) +1;        //sagdakiler+soldakiler+kok...
    }
}

//ORTALAMA HESAPLAMA FONKSIYONU
int ortalama(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        //sol tarafa gidiyo
        int sol= ortalama(root->sol);
        //koku dahil ettik
        int kok= root->no;
        //sag taraf
        int sag= ortalama(root->sag);
        int toplam= sol+sag+kok;    //hepsini toplayip daha sonra elemansayisina bolunecek
        return toplam;

    }

}

//INORDER DOLASMA FONKSIONU
void inorder(struct node* root)            //sol-kok-sag sirasinda gezilcek...
{
    if(root!=NULL)
    {
        inorder(root->sol);
        printf("--------------------------\n");
        printf("Numara: %d  Isim:%s\n",root->no,root->ad);
        inorder(root->sag);
    }
}

int main()
{
    struct node *root = NULL;       //baslangicta agac bos olacak sekilde ayarliyoruz
    char ad[10];
    int secim,elemansayisi;
    char silinecek[10];

    do
    {
        printf("\n----------------------------------------------------------\n");
        printf("MENU:\n1-EKLEME\n2-SILME\n3-AGAC YUKSEKLIGI BULMA\n4-ORTALAMA BUL\n5-AD'A GORE LISTELEME\n6-INORDER LISTELEME\n7-CIKIS\n");
        printf("\nSeciminiz:");
        scanf("%d",&secim);
        switch(secim)
        {
        case 1:
            root = veriOkuVeEkle(root, "veriler.txt");
            printf("----------------------------------------------------------\n");
            printf("Tum elemanlar basariyla eklendi.");

            break;
        case  2:
            printf("----------------------------------------------------------\n");
            printf("Silmek istediginiz adi girin:");
            scanf("%s",silinecek);
            root = silme(root, silinecek);
            printf("----------------------------------------------------------\n");
            printf("%s adina sahip dugum silindi.",silinecek);
            break;
        case 3 :
            printf("----------------------------------------------------------\n");
            printf("Agacin yuksekligi %d'dir.",yukseklik(root));
            break;
        case  4:
            elemansayisi= say(root);
            int ort= ortalama(root) / elemansayisi;
            printf("----------------------------------------------------------\n");
            printf("Tum koklerin ortalamasi %d'dir.", ort);
            break;
        case 5:
            printf("----------------------------------------------------------\n");
            tekrarSayisiFazlaOlanlariListele(root);
            break;
        case  6:
            printf("----------------------------------------------------------\n");
            printf("Tum elemanlar inorder olarak listelenmistir.\n");
            inorder(root);
            break;
        case  7:
            printf("----------------------------------------------------------\n");
            printf("Cikis yapiliyor...\n");
            break;
        default:
            printf("----------------------------------------------------------\n");
            printf("Lutfen 1-6 arasinda sayi giriniz!");
        }
    }

    while(secim!=7);
    return 0;
}
