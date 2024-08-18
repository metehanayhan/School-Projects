# METEHAN AYHAN

import random

kelimeler = ["system", "data", "algorithm", "such", "base", "node", "model", "case", "program", "information", "set",
             "code", "function", "process", "application", "software", "class", "point", "type", "network", "tree",
             "object", "element", "input", "operation", "level", "memory", "table", "order", "file", "variable",
             "language", "write", "list", "structure", "compute", "sequence", "computer", "bit", "probability",
             "machine", "array", "page", "error", "step", "search", "most", "path", "graph", "web", "length", "several",
             "security", "proof", "access", "obtain", "matrix", "task", "image", "form", "return", "interface",
             "resource", "address", "implementation", "loop", "first", "read", "location", "hardware", "behavior",
             "programming", "field", "key", "parameter", "distribution", "definition", "instance", "interaction",
             "internet", "representation", "edge", "stack", "return", "procedure", "link", "output", "block", "domain",
             "store", "call", "device", "server", "static", "dataset", "detection", "write", "execute", "least", "key"]

rastgele = random.randint(0, len(kelimeler) - 1)  # liste boyutu arasında rastgele sayi urettik.
tus = 1                                           # random choice kullanmamak icin..
while tus != 0:
    kelime = kelimeler[rastgele]  # rastgele kelimemizi olusturduk.
    print(kelime)  # kontrol amaclı koydum.
    tahmin_hakki = 0
    puan = 0
    if len(kelime) % 2 == 0:              # burada tahmin hakki sayisini hesapladik..
        tahmin_hakki = len(kelime) // 2
    else:
        tahmin_hakki = (len(kelime) // 2) + 1

    yeni_kelime = ""   # bos bir obje olusturduk her bilinen harf bunun icine atilcak.

    while True:
        kelime_gosterim = ""    # ekranda gosterilecek kelime
        for i in kelime:
            if i in yeni_kelime:
                kelime_gosterim += i  # tahmin edilen harf kelimenin icinde bulunuyosa onu yazacak yoksa alt tire koycak
            else:
                kelime_gosterim += "_"

        kontrol = True
        for i in kelime:
            if i in yeni_kelime:   # kelimenin harfleri tahmin edilenlerle ayniysa kazandiniz yazisi cikacak
                continue
            else:
                kontrol = False
                break

        if kontrol:
            print("------------------------")
            print("Kazandınız. Puaniniz:{}".format(puan))
            tus = input("Yeniden oynamak icin herhangi bir tusa, cikmak icin 0'a basınız.")
            if tus == "0":
                print("------------------------")
                print("Cikis yapildi.")
                break

            else:                   # burada tum verileri sifirladik yeni oyun icin
                yeni_kelime = ""
                rastgele = random.randint(0, len(kelimeler) - 1)
                kelime = kelimeler[rastgele]
                print(kelime)
                tahmin_hakki = 0
                puan = 0
                if len(kelime) % 2 == 0:
                    tahmin_hakki = len(kelime) // 2
                else:
                    tahmin_hakki = (len(kelime) // 2) + 1

                continue

        print("------------------------")
        print("Kalan hak:{}  Puan:{}".format(tahmin_hakki, puan))
        print("Kelimeniz:{}".format(kelime_gosterim))

        tahmin = input("Harf giriniz:").lower()
        if len(tahmin) != 1:
            print("------------------------")
            print("Lütfen 1 harf girin!")
            continue

        if tahmin in "ç, ğ, ö, ş, ı, ü":          # turkce karakter girerse uyari veriyor
            print("------------------------")
            print("Lütfen Türkçe karakter kullanmayın!")
            continue

        if tahmin in kelime_gosterim:         # onceden bilinen kelime icin yeniden puan alinmamasi icin..
            print("------------------------")
            print("Daha önce tahmin edilmiş!")
            continue

        if tahmin in kelime:
            print("------------------------")
            print("Doğru tahmin")

            kac_kere = 0
            for i in kelime:
                if tahmin == i:
                    kac_kere += 1
                else:
                    continue

            if tahmin in "a,e,i,o,u":    # sesli harfse ona gore puan hesaplamasi
                puan += 3 * kac_kere
            else:
                puan += 2 * kac_kere
            yeni_kelime += tahmin

        else:
            tahmin_hakki -= 1
            puan -= 4
            print("------------------------")
            print("Yanlis tahmin")

        if tahmin_hakki == 0:
            print("------------------------")
            print("Kaybettiniz. Puaniniz:{}".format(puan))
            print("Kelimeniz:{} idi".format(kelime))
            break

    break
