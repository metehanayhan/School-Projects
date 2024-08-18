# Kullanıcıdan alınan string içerisindeki sesli ve sessiz harfleri ayırarak
# ekranda gösteren Python kodunu yazınız

kelime = input("Bir kelime giriniz:")

sesli = "a,e,ı,i,o,ö,u,ü"
a = ""
b = ""
for i in kelime:
    if i in sesli:
        if i not in a:
            a += i

    else:
        if i not in b:
            b += i

print("Sesli harfler:{}".format(a))
print("Sessiz harfler:{}".format(b))
