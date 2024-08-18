# Kullanıcıdan alınan bir cümle içerisindeki kelime sayısını bulan,
# aranan kelimenin olup olmadığını söyleyen ve cümledeki boşlukları kaldıran ve
# tüm a harflerini e harfine çeviren Python kodunu yazınız

cumle = input("Bir cümle giriniz:").strip()

kelimesayisi = 1
for i in cumle:
    if i == " ":
        kelimesayisi += 1
print("Cümledeki kelime sayısı:{}".format(kelimesayisi))
aranan = input("Aranan kelimeyi giriniz:")
cumlemiz = cumle.split(" ")
if aranan in cumlemiz:
    print("Aranan kelime cümlede var.")
else:
    print("Aranan kelime cümlede yok.")

yenicumle = cumle.lower().replace(" ", "").replace("a", "e")
print(yenicumle)
