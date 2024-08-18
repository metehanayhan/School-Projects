# kullanicidan kac adet sayi girileceği bilgisini alan ve bunlarin üsleri toplamini bulan kod

adet = int(input("kac adet sayi girilecek:"))
toplam = 0
while adet > 0:
    rakam = int(input("sayi gir:"))
    toplam += rakam ** 2
    adet -= 1
print(toplam)
