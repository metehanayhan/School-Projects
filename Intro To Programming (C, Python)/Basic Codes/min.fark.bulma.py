import random

sayilar = []

while True:
    rsayi = random.randint(1, 100)
    sayilar.append(rsayi)
    print(rsayi, end="\t")
    if rsayi >= 70 and rsayi <= 75:
        break

min_fark = 100
min_sayi1 = 0
min_sayi2 = 0

for i in range(len(sayilar) - 1):
    fark = abs(sayilar[i] - sayilar[i+1])
    if fark < min_fark:
        min_fark = fark
        min_sayi1 = sayilar[i]
        min_sayi2 = sayilar[i+1]

print("\n\nMinumum Fark = {}\nSayi1 = {}\nSayi2 = {}".format(min_fark, min_sayi1, min_sayi2))
