# 1-100 arasi rastgele sayiyi 5 kerede tahmin etme oyunu

import random
import sys

sayi = random.randint(1, 100)
print(sayi)
for i in range(5):
    tahmin = int(input("tahmin:"))
    if sayi < tahmin:
        print("asagi!")
    elif sayi > tahmin:
        print("yukari!")
    elif sayi == tahmin:
        print("Tebrikler bildiniz!")
        sys.exit()

print("Uzgunuz bilemediz sayi {} idi..".format(sayi))
