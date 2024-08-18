import random
listem = []

for i in range(15):
    listem.append(random.randint(0, 15))

print(listem)
frekans = 0
f_list = []
max_frekans = 0
m = 0

for i in listem:
    for j in range(len(listem)):
        if i == listem[j]:
            frekans += 1
            if frekans > max_frekans:
                max_frekans = frekans
                m = j
        else:
            continue

    f_list.append(frekans)
    frekans = 0

print(f_list)
print("Max frekans:{} Sayı:{}".format(max_frekans, listem[m]))
