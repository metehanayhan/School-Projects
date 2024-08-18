# Kullanıcı çıkış için ‘c’ girmediği sürece yeni sayı alınız
# Girilen sayı 2 basamaklı ise İki basamaklı Armstrong sayı yoktur
# Sayının basamak sayısı 5 ten fazlaysa En fazla 5 basamak kabul ediyoruz mesajlarını veriniz
import sys

while True:
  sayi = input("sayi girin:")
  if sayi == "c":
      sys.exit()
  else:
   uzunluk = int(len(sayi))
   if uzunluk == 2:
       print("İki basamaklı Armstrong sayı yoktur")
   elif uzunluk > 5:
       print("En fazla 5 basamak kabul ediyoruz")
   else:
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
