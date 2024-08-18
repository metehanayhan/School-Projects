import random
liste = []

for i in range(15):
    liste.append(random.randint(0, 15))

print(liste)

for i in range(len(liste)):
    for j in range(len(liste)):
        if liste[i] > liste[j]:
            temp = liste[i]
            liste[i] = liste[j]
            liste[j] = temp
        else:
            continue

print(liste)
