# kullanicidan negatif sayi girilene kadar sayi isteyip ortama bulan algoritma

sayi = 1
sayac = 0
toplam = 0
while sayi > 0:
    sayi = int(input("sayi gir:"))
    toplam += sayi
    sayac += 1
print("ortalama:{}".format(toplam // sayac))
