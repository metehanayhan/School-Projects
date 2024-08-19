//METEHAN AYHAN


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dugum {
    char veri;
    struct Dugum* sonraki;
};

struct Yigin {
    struct Dugum* ust;
};

//void yigiBaslat(struct Yigin* yigin) {
   // yigin->ust = NULL;}

void yigeEkle(struct Yigin* yigin, char veri) {
    struct Dugum* yeniDugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeniDugum->veri = veri;
    yeniDugum->sonraki = yigin->ust;
    yigin->ust = yeniDugum;
}

char yigindanCikar(struct Yigin* yigin) {
    if (yigin->ust == NULL) {
        return '\0';
    }
    char veri = yigin->ust->veri;
    struct Dugum* gecici = yigin->ust;
    yigin->ust = yigin->ust->sonraki;
    free(gecici);
    return veri;
}

int oncelik(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0;
}

void infixiPostfixeDonustur(char* infix, char* postfix, FILE* dosya) {
    struct Yigin yigin;
   // yigiBaslat(&yigin);
    yigin.ust = NULL;
    int i = 0, j = 0;

    fprintf(dosya, "Infix\t\tYigin\t\tPostfix\n");

    while (infix[i] != '\0') {
        fprintf(dosya, "%s\t\t", infix + i);

        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[j++] = infix[i];
            fprintf(dosya, "Bos.\t\t");
        } else if (infix[i] == '(') {
            yigeEkle(&yigin, '(');
            fprintf(dosya, "Bos.\t\t");
        } else if (infix[i] == ')') {
            while (yigin.ust != NULL && yigin.ust->veri != '(') {
                postfix[j++] = yigindanCikar(&yigin);
            }
            if (yigin.ust != NULL && yigin.ust->veri == '(') {
                yigindanCikar(&yigin);
            }
            fprintf(dosya, "Bos.\t\t");
        } else {
            while (yigin.ust != NULL && oncelik(infix[i]) <= oncelik(yigin.ust->veri)) {
                postfix[j++] = yigindanCikar(&yigin);
            }
            yigeEkle(&yigin, infix[i]);
            fprintf(dosya, "%c\t\t", yigin.ust->veri);
        }

        postfix[j] = '\0';
        fprintf(dosya, "%s\n", postfix);
        i++;
    }

    while (yigin.ust != NULL) {
        postfix[j++] = yigindanCikar(&yigin);
    }

    postfix[j] = '\0';
    fprintf(dosya, "Bos.\t\tBos.\t\t%s\n", postfix);
}

int main() {
    char infix[100];
    char postfix[100];

    printf("VERI YAPILARI 3. ODEV\nMETEHAN AYHAN\n22100011024\n\n");
    printf("Infix ifadeyi girin: ");
    scanf("%s", infix);

    FILE* dosya = fopen("sonuc.txt", "w");
    infixiPostfixeDonustur(infix, postfix, dosya);

    fclose(dosya);

    // Dosyanın tamamını oku ve ekrana yazdır
    dosya = fopen("sonuc.txt", "r");
    if (dosya == NULL) {
        printf("Dosya açma hatası!");
        return 1;
    }

    char satir[256];  // Her satır en fazla 255 karakter olabilir
    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        printf("%s", satir);
    }

    printf("Islem Sonucu: %s",postfix);
    fclose(dosya);

    return 0;
}
