# METEHAN AYHAN (TC NO)

toplam = 0
toplam2 = 0
toplam3 = 0
sonuc = 0
tus = 1

while True:
    if tus == "0":
        print("----------------------")
        print("Çıkış yapıldı..")
        break
    print("----------------------")
    tc = input("Tc'nizi girin:")
    if tc != " " and tc != "" and len(tc) == 11 and tc[0] != "0" and tc.isdigit() is True:
        for i in range(0, 10, 1):  # 1-10 bas toplamı
            toplam3 += int(tc[i])
            toplam3 = toplam3 % 10
        if toplam3 == int(tc[10]):
            for i in range(0, 10, 2):  # 13579 bas top
                toplam += int(tc[i])
            toplam = toplam * 7
            for i in range(1, 9, 2):  # 2468 bas top
                toplam2 += int(tc[i])
                sonuc = toplam - toplam2
            sonuc %= 10
            if int(sonuc) == int(tc[9]):
                print("----------------------")
                print("Girilen tc doğru!")
            else:
                print("----------------------")
                print("Girilen tc yanlış!")
        else:
            print("----------------------")
            print("Girilen tc yanlış!")
    else:
        print("----------------------")
        print("Girilen tc yanlış!")

    print("----------------------")
    tus = input("Çıkmak için 0'a yeni TC sorgusu için bir tuşa basınız:")
