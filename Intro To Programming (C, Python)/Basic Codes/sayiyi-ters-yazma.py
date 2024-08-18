# sayiyi tersten yazdiran kod

sayi = int(input("sayi gir:"))
toplam = 0

while sayi != 0:
      toplam *= 10
      toplam = toplam + sayi % 10
      sayi = sayi // 10

print(toplam)