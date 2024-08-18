# Liste veri tipi kullanılarak kullanıcıdan alınan öğrenci isim, numara
# ve vize notu bilgilerini ayrı listelerde tutunuz. Tüm öğrenci bilgilerini ve
# vize notu 70 den büyük olan öğrencilerin bilgilerini ayrı ayrı listeleyiniz.

ogr_sayisi = int(input("Kaç öğrenci bilgisi gireceksiniz:"))

adlar = []
numaralar = []
vizeler = []
for i in range(ogr_sayisi):
    adlar.append(input("Öğrencinin adını giriniz:"))
    numaralar.append(int(input("Öğrencinin numarasını giriniz:")))
    vizeler.append(int(input("Öğrencini vize motunu giriniz:")))

print("Öğrenci adları -> {}".format(adlar))
print("Öğrenci numaraları -> {}".format(numaralar))
print("Öğrenci vize notları -> {}".format(vizeler))

print("Tüm öğrenciler")
for i in range(ogr_sayisi):
    print("{}. Öğrencinin adı:{} Numarası:{} Vize notu:{}".format(i+1, adlar[i], numaralar[i], vizeler[i]))

print("Vize notu 70'ten yüksek olan öğrenciler:")
for i in range(ogr_sayisi):
    if vizeler[i] > 70:
        print("Öğrencinin adı:{} Numarası:{} Vize notu:{}".format(i + 1, adlar[i], numaralar[i], vizeler[i]))
