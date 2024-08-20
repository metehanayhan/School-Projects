// METEHAN AYHAN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Dugum {
    int komsu_no;
    int agirlik;
    struct Dugum* sonraki;
};

// Graf yapisi. dugum sayisini ve komsuluk listelerini iceriyor..
struct Graf {
    int dugum_sayisi;
    struct Dugum** komsuluk_listeleri;
};

// Yeni bir dugum olusturma foksiyonu..    geriye yeni dugumu dondurecekk
struct Dugum* dugum_olustur(int komsu_no, int agirlik) {
    struct Dugum* yeni_dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeni_dugum->komsu_no = komsu_no;
    yeni_dugum->agirlik = agirlik;
    yeni_dugum->sonraki = NULL;
    return yeni_dugum;
}

// Yeni bir graf olusturmak icin..
struct Graf* graf_olustur(int dugum_sayisi) {
    struct Graf* graf = (struct Graf*)malloc(sizeof(struct Graf));
    graf->dugum_sayisi = dugum_sayisi;
    graf->komsuluk_listeleri = (struct Dugum**)malloc(dugum_sayisi * sizeof(struct Dugum*));

    // Komsuluk listelerini baslangicta NULL olarak ayarlıyotuz ki bos olsunlar
    for (int i = 0; i < dugum_sayisi; i++) {
        graf->komsuluk_listeleri[i] = NULL;
    }
    return graf;
}

// Yeni bir kenar ekleme fonksiyonu..
void kenar_ekle(struct Graf* graf, int kaynak, int hedef, int agirlik) {

    // Yeni dugum olusturur ve komsuluk listesine ekler
    struct Dugum* yeni_dugum = dugum_olustur(hedef, agirlik);
    yeni_dugum->sonraki = graf->komsuluk_listeleri[kaynak];
    graf->komsuluk_listeleri[kaynak] = yeni_dugum;
}

// Grafi yazdirmak icin fonksiyon..
void graf_yazdir(struct Graf* graf) {
    printf("------------------------------------\n");
    printf("Graf Yapisi:\n");
    for (int i = 0; i < graf->dugum_sayisi; i++) {
        struct Dugum* temp = graf->komsuluk_listeleri[i];
        printf("%d: ", i);
        while (temp) {
            printf("(%d, %d) ", temp->komsu_no, temp->agirlik);
            temp = temp->sonraki;
        }
        printf("\n");
    }
}

// Yigin yapisi..
struct Yigin {
    int kapasite;
    int tepe;
    int* dizi;
};

// Yeni bir yigin olusturur
struct Yigin* yigin_olustur(int kapasite) {
    struct Yigin* yigin = (struct Yigin*)malloc(sizeof(struct Yigin));
    yigin->kapasite = kapasite;
    yigin->tepe = -1;
    yigin->dizi = (int*)malloc(yigin->kapasite * sizeof(int));
    return yigin;
}

// Yigina eleman ekler
void yigin_ekle(struct Yigin* yigin, int eleman) {
    yigin->dizi[++yigin->tepe] = eleman;
}

// Yigindan eleman cikarir
int yigin_cikar(struct Yigin* yigin) {
    if (yigin->tepe == -1) {
        printf("Yigin bos!\n");
        return -1;
    }
    return yigin->dizi[yigin->tepe--];
}

// Yigin bos mu kontrol eder
int yigin_bos_mu(struct Yigin* yigin) {
    return yigin->tepe == -1;
}

// Kuyruk yapisi
struct Kuyruk {
    int bas;
    int son;
    int kapasite;
    int* dizi;
};

// Yeni bir kuyruk olusturur
struct Kuyruk* kuyruk_olustur(int kapasite) {
    struct Kuyruk* kuyruk = (struct Kuyruk*)malloc(sizeof(struct Kuyruk));
    kuyruk->kapasite = kapasite;
    kuyruk->bas = kuyruk->son = -1;
    kuyruk->dizi = (int*)malloc(kuyruk->kapasite * sizeof(int));
    return kuyruk;
}

// Kuyruga eleman ekler
void kuyruk_ekle(struct Kuyruk* kuyruk, int eleman) {
    if (kuyruk->son == kuyruk->kapasite - 1) {
        printf("Kuyruk dolu!\n");
        return;
    }
    if (kuyruk->bas == -1)
        kuyruk->bas = 0;
    kuyruk->dizi[++kuyruk->son] = eleman;
}

// Kuyruktan eleman cikarir
int kuyruk_cikar(struct Kuyruk* kuyruk) {
    if (kuyruk->bas == -1) {
        printf("Kuyruk bos!\n");
        return -1;
    }
    int eleman = kuyruk->dizi[kuyruk->bas];
    if (kuyruk->bas == kuyruk->son)
        kuyruk->bas = kuyruk->son = -1;
    else
        kuyruk->bas++;
    return eleman;
}

// Kuyruk bos mu kontrol eder
int kuyruk_bos_mu(struct Kuyruk* kuyruk) {
    return kuyruk->bas == -1;
}

// Derinlik oncelikli arama (DFS) algoritmasi
void dfs(struct Graf* graf, int baslangic_dugumu) {
    // Ziyaret edildi bilgisini tutar
    int* ziyaret_edildi = (int*)malloc(graf->dugum_sayisi * sizeof(int));
    for (int i = 0; i < graf->dugum_sayisi; ++i)
        ziyaret_edildi[i] = 0;

    // Yigina baslangic dugumunu ekler
    struct Yigin* yigin = yigin_olustur(graf->dugum_sayisi);
    yigin_ekle(yigin, baslangic_dugumu);

    while (!yigin_bos_mu(yigin)) {
        int suanki_dugum = yigin_cikar(yigin);

        // Dugum ziyaret edilmediyse ziyaret et ve isaretle
        if (!ziyaret_edildi[suanki_dugum]) {
            printf("%d ", suanki_dugum);
            ziyaret_edildi[suanki_dugum] = 1;
        }

        // Komsu dugumleri yigina ekler
        struct Dugum* temp = graf->komsuluk_listeleri[suanki_dugum];
        while (temp) {
            int komsu_dugum = temp->komsu_no;
            if (!ziyaret_edildi[komsu_dugum])
                yigin_ekle(yigin, komsu_dugum);
            temp = temp->sonraki;
        }
    }

    // Bellek temizleme
    free(ziyaret_edildi);
    free(yigin->dizi);
    free(yigin);
}

// Genislik oncelikli arama (BFS) algoritmasi
void bfs(struct Graf* graf, int baslangic_dugumu) {
    // Ziyaret edildi bilgisini tutacak..
    int* ziyaret_edildi = (int*)malloc(graf->dugum_sayisi * sizeof(int));
    for (int i = 0; i < graf->dugum_sayisi; ++i)
        ziyaret_edildi[i] = 0;

    // Kuyruga baslangic dugumunu ekleme
    struct Kuyruk* kuyruk = kuyruk_olustur(graf->dugum_sayisi);
    kuyruk_ekle(kuyruk, baslangic_dugumu);
    ziyaret_edildi[baslangic_dugumu] = 1;

    while (!kuyruk_bos_mu(kuyruk)) {
        int suanki_dugum = kuyruk_cikar(kuyruk);
        printf("%d ", suanki_dugum);

        // Komsu dugumleri kuyruga ekleme
        struct Dugum* temp = graf->komsuluk_listeleri[suanki_dugum];
        while (temp) {
            int komsu_dugum = temp->komsu_no;
            if (!ziyaret_edildi[komsu_dugum]) {
                kuyruk_ekle(kuyruk, komsu_dugum);
                ziyaret_edildi[komsu_dugum] = 1;
            }
            temp = temp->sonraki;
        }
    }

    // Bellek temizleme islemleri..
    free(ziyaret_edildi);
    free(kuyruk->dizi);
    free(kuyruk);
}


int min(struct Graf* graf) {
    int en_kucuk = INT_MAX;
    for (int i = 0; i < graf->dugum_sayisi; ++i) {
        if (graf->komsuluk_listeleri[i] != NULL && i < en_kucuk)
            en_kucuk = i;
    }
    return en_kucuk;
}

int main() {
    //dosya okuma
    FILE *dosya;
    dosya = fopen("graf.txt", "r");

    if (dosya == NULL) {
        printf("Dosya acma hatasi!");
        return 1;
    }

    int dugum_sayisi;
    fscanf(dosya, "%d", &dugum_sayisi);

    //graf olusturuyoruz..
    struct Graf* graf = graf_olustur(dugum_sayisi);

    char satir[100];
    while (fgets(satir, sizeof(satir), dosya)) {
        int kaynak;
        sscanf(satir, "%d", &kaynak);

        char temp[100];
        strcpy(temp, satir);

        char *token = strtok(temp, "-, ");
        token = strtok(NULL, "-, ");
        while (token != NULL) {
            int hedef, agirlik;
            sscanf(token, "%d", &hedef);
            token = strtok(NULL, "-, ");
            sscanf(token, "%d", &agirlik);
            kenar_ekle(graf, kaynak, hedef, agirlik);
            token = strtok(NULL, "-, ");
        }
    }

    fclose(dosya);
    graf_yazdir(graf);
    int baslangic_dugumu = min(graf);

    //ve en son dfs bfs yi yazdirip bitiriyoruz..
    printf("------------------------------------\n");
    printf("DFS Dolasma Sonucu: ");
    dfs(graf, baslangic_dugumu);
    printf("\n");
    printf("------------------------------------\n");
    printf("BFS Dolasma Sonucu: ");
    bfs(graf, baslangic_dugumu);
    printf("\n------------------------------------\n");

    return 0;
}
