# METEHAN AYHAN

while True:  # once sonsuz dongu olusturduk kullanici 3e basana kadar tekrarlayacak.
    print("----------------------------------------")
    print("1 - İkilik tabandan onluk tabana cevirme")
    print("2 - Onluk tabandan ikilik tabana cevirme")
    print("3 - Cikis")
    tus = input("Secimiz(1-3): ")
    print("----------------------------------------")

    if tus == "1":
        ikilik = input("Lütfen ikilik tabanda bir sayı girin: ")
        kontrol = True  # burada kontrol degiskesni olusturup doğru olarak ayarladık eger sayının icinde 1 0 yoksa
        # false donecek
        for rakam in ikilik:  # sayiyi string olarak aldigi icin donguyle her rakami kontrol ettik
            if rakam not in ("0", "1"):
                kontrol = False
                break

        while kontrol is False:  # 1 ve 0 icerene kadar kullaniciya soracak
            ikilik = input("sadece 0 ve 1 giriniz! : ")
            kontrol = 1
            for rakam in ikilik:
                if rakam not in ("0", "1"):
                    kontrol = False
                    break
        onluk_sayi = 0
        for i in range(len(ikilik)):  # basamak sayisi kadar dongu actik
            onluk_sayi += int(ikilik[i]) * 2 ** (len(ikilik) - i - 1)  # cevirme islemini yaptik.

        print("Onluk tabanda:", onluk_sayi)

    elif tus == "2":
        onluk_sayi = int(input("sayi giriniz: "))

        ikilik = ""  # ikilik sayi diye degisken olusturmak icin yaptım bir de str olmalı
        while onluk_sayi > 0:
            kalan = onluk_sayi % 2
            ikilik = str(kalan) + ikilik
            onluk_sayi = onluk_sayi // 2

        print("+++ sonuc:", ikilik)

    elif tus == "3":
        print("+++ cikis yapildi...")
        break  # tum while dongusunden cikiyor program sonlaniyor.

    else:
        print("+++1 ve 3 arasinda sayi giriniz!+++")  # 1-3 ten baska sayi girerse uyari veriyoruz.
