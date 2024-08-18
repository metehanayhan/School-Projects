# armstrong = basamaklari kupleri toplami kemdisine esit olan sayilari bulma kodu


sayi = input("sayi gir:")
uzunluk = int(len(sayi))

toplam = 0
sayi = int(sayi)
sayi2 = sayi

while sayi != 0:
    a = sayi%10
    toplam = toplam + a**3
    sayi = sayi // 10

if sayi2 == toplam:
    print("{} sayisi armstrong sayidir.".format(sayi2))
else:
    print("Bu sayi armstrong degil.")