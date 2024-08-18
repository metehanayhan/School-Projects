# 1-100 arasi 70-75 olana kadar sayi üret ardisik min fark bul

import random

sayi1 = 0
minfark = 100
minsayi1 = 0
minsayi2 = 0

while True:
    rsayi = random.randint(1, 100)
    print(rsayi, end="\t")
    if sayi1 == 0:
        sayi1 = rsayi
        minsayi1 = rsayi
        minsayi2 = rsayi
    else:
        if abs(sayi1 - rsayi) < minfark:
            minfark = abs(sayi1 - rsayi)
            minsayi1 = sayi1
            minsayi2 = rsayi
    sayi1 = rsayi
    if 70 <= rsayi <= 75:
        break

print("\n\nMinumum Fark = {}\nSayi1 = {}\nSayi2 = {}".format(minfark, minsayi1, minsayi2))
