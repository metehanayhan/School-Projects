# asal sayilar ve miktarı

sayi = int(input("sayi girin:"))
kontrol=0
sayac=0

for i in range(2, sayi):
   kontrol=0
   for k in range(2,i):
       if i%k==0:
           kontrol=1
   if kontrol==0:
       print(i)
       sayac+=1

print("{} tane sayı bulundu".format(sayac))

