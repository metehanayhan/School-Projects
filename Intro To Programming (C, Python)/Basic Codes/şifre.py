# sifre en az 8 en fazla 12 karakter icermeli
# sayi ile baslayıp bitemez
# en az 1 büyük ve kücük harf icermeli
# bosluk iceremez
# en az 1 tane alfanümerik olmayan karakter icermelidir
# tekrarlayan karakter bulunmamalı
# bir de kendin 2 özel kriter belirle

sifre = input("Şifreyi giriniz:")

kontrol = True
if sifre.islower() == True or sifre.isupper() == True:
    kontrol = False

for i in sifre:
    if sifre.count(i) > 1:
        kontrol = False

if len(sifre) < 8 or len(sifre) > 12:
    print("Şifre formata uygun değil!")
elif sifre[-1].isdigit() == True or sifre[0].isdigit() == True:
    print("Şifre formata uygun değil!")
elif sifre in " ":
    print("Şifre formata uygun değil!")
elif kontrol == False:
    print("Şifre formata uygun değil!")
elif sifre.isalnum() != True:
    print("Şifre formata uygun değil!")
else:
    print("Şifre formata uygundur.")
