# Verilen bir liste içindeki listedeki sayıların başka bir liste içinde olup
# olmadığını kontrol eden Python kodunu yazınız

liste1 = [[1, 2, 3], [9, 2, 6], [5, 8, 7], [4, 6, 10]]
liste2 = [9, 5, 7, 3, 8, 5, 2, 1, 0, 7]

for i in range(len(liste1)):
    for j in range(len(liste1[i])):
        if liste1[i][j] not in liste2:
            continue
        else:
            print(liste1[i])
            break
