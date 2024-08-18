# polindrom: tersi kendisine esit olan
kelime = input("kelime gir: ")

kontrol = True
for i in range(len(kelime) // 2):
    if kelime[i] != kelime[len(kelime) - i - 1]:
        kontrol = False

if kontrol:
    print("bu kelime polindromdur.")
else:
    print("bu kelime polindrom degil!")

print(*kelime[::-1])  # * kelimeyi parcaladi