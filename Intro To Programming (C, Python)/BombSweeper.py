# METEHAN AYHAN

import random
import sys

tus = 1
while tus != 0:

    # Kullanıcıdan oyun modunu aldık
    print("-------------------------------")
    oyun_modu = input("1 - Açık mod\n2 - Gizli mod\nOyun modunu seçin: ")
    while oyun_modu not in ["1", "2"]:
        print("-------------------------------")
        oyun_modu = input("Geçerli bir oyun modu girin (1/2): ")

    # Oyun alanı boyutunu alıyoruz minimum 10x10 olmalı
    print("-------------------------------")
    alan_boyutu = int(input("Oyun alanını giriniz (min 10x10): "))
    while alan_boyutu < 10:
        print("-------------------------------")
        alan_boyutu = int(input("Geçerli bir oyun alanı boyutu giriniz (min 10x10): "))

    # Mayın sayısını hesapladık oyun alanının %30'u kadar olacak sekilde..
    mayin_sayisi = int(alan_boyutu * alan_boyutu * 0.3)

    # Oyun alanı oluşturuyoruz tüm hücreler ? ile dolcak açık mod istenirse mayınlar gösterilcek
    oyun_alani = [["?" for _ in range(alan_boyutu)] for _ in range(alan_boyutu)]

    # Mayınları yerleştirdik
    for i in range(mayin_sayisi):
        while True:
            satir = random.randint(0, len(oyun_alani) - 1)
            sutun = random.randint(0, len(oyun_alani) - 1)
            if oyun_alani[satir][sutun] != "X":
                oyun_alani[satir][sutun] = "X"
                break

    # Oyunun baslangıç durumunu gösteriyoruz
    print("-------------------------------")
    print(f"Oyun alanı ({oyun_modu} mod):")
    for i in range(len(oyun_alani)):
        for j in range(len(oyun_alani[i])):
            if oyun_modu == "2" and oyun_alani[i][j] == "X":
                print("?", end=" ")
            else:
                print(oyun_alani[i][j], end=" ")
        print()

    acik_mod = oyun_modu == "1"
    puan = 0

    # Kullanıcının oyunu oynadığı döngüyü kurduk
    while True:
        # Kullanıcıdan satır ve sütun bilgisini istedik
        print("-------------------------------")
        satir = int(input("Satır seçiniz: ")) - 1
        sutun = int(input("Sütun seçiniz: ")) - 1
        print("-------------------------------")

        # Seçilen indexi kontrol ediyoruz
        if oyun_alani[satir][sutun] == "X":
            for i in range(len(oyun_alani)):
                for j in range(len(oyun_alani[i])):
                    if oyun_alani[i][j] == "X":
                        print("X", end=" ")
                    else:
                        print(oyun_alani[i][j], end=" ")
                print()
            print("-------------------------------")
            print("Mayına bastın, maalesef oyunu kaybettiniz!")
            tus = input("Çıkmak için 0'a, Yeniden oynamak için herhangi bir tuşa basınız:")

            if tus == "0":
                print("-------------------------------")
                print("Çıkış yapıldı..")
                sys.exit()
            else:
                break
        else:
            # Seçilen hücrenin etrafındaki hücrelerde kaç tane mayın var sayıyoruz
            mayin_sayisi = 0
            for i in range(max(satir - 1, 0), min(satir + 2, alan_boyutu)):
                for j in range(max(sutun - 1, 0), min(sutun + 2, alan_boyutu)):
                    if oyun_alani[i][j] == "X":
                        mayin_sayisi += 1

            # Puanı güncelliyoruz ve indexin içeriğini açıyoruz
            # her hamleye 1 puan verdim böylece 10x10luk tarlada 70 tane bilirse %70i kadar puan almış olur dedim..
            if oyun_alani[satir][sutun] != "?":
                print("Bu hücre daha önce açıldı, farklı bir hücre seçin!")
                print("-------------------------------")
            else:
                puan += 1
                oyun_alani[satir][sutun] = str(mayin_sayisi)

            # Oyun alanını gösteriyoruz
            for i in range(len(oyun_alani)):
                for j in range(len(oyun_alani[i])):
                    if not acik_mod and oyun_alani[i][j] == "X":
                        print("?", end=" ")
                    else:
                        print(oyun_alani[i][j], end=" ")
                print()

            # Tüm hücreleri açtıysak oyunu bitiriyoruz
            if sum([row.count("?") for row in oyun_alani]) == mayin_sayisi:
                print("-------------------------------")
                print("Tebrikler, kazandınız!")
                break

            print("-------------------------------")
            print(f"Puanınız: {puan}")
    continue
