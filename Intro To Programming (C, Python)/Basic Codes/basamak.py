# basamak toplamı ve sayisi

sayi = input("sayi giriniz:")

print("Basamak sayisi:",len(sayi))

toplam=0
for i in sayi:
  toplam+=int(i)

print("Basamak toplamı:",toplam)
