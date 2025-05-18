def printaj_listu(lista):
    for el in lista:
        print(el, end=" ")

# 1. korak je unos liste
l = []
while True:
    n = int(input())
    if n != 0:
        l.append(n)
    else:
        break

# 2. korak je izdvajanje poz i neg
pozitivni = []
negativni = []

for el in l:
    if el > 0:
        pozitivni.append(el)
    else:
        negativni.append(el)

# 3. korak je printanje
printaj_listu(negativni)
print()
printaj_listu(pozitivni)

