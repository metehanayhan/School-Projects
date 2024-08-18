# maas hesaplama

maas = int(input("mevcut maaşı girin:"))
cocuksayisi = int(input("çocuk sayısını girin:"))
eskizam = int(input("eski zam miktarını girin:"))

extrazam = cocuksayisi * 70

if maas < 3000:
    zam = maas / 100 * 20

elif 3000 < maas < 4000:
    zam = maas / 100 * 15
else:
    zam = maas / 100 * 10

if zam < eskizam:
    maas += eskizam
else:
    maas += zam

maas += extrazam
print("yeni maaş:", maas)
if zam > eskizam:
    print("zam miktari:", zam)
else:
    print("zam miktari:", eskizam)
