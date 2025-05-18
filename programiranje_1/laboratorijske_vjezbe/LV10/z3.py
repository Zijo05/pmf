import random

def generisi_random_rijec(n):
    rijec = ""

    for i in range(n):
        malo_veliko = random.randint(1,2)
        if malo_veliko == 1:
            # malo slovo
            slovo = random.randint(ord("a"), ord("z"))
        else:
            # veliko slovo
            slovo = random.randint(ord("A"), ord("Z"))

        rijec += chr(slovo)

    return rijec


m = int(input("Broj rijeci: "))
n = int(input("Duzina rijeci: "))

sve_rijeci = []
for i in range(m):
    rijec = generisi_random_rijec(n)
    sve_rijeci.append(rijec)

print(sve_rijeci)

fajl = open("slucajne_rijeci.txt", "w")

for i in range(len(sve_rijeci)):
    rijec = sve_rijeci[i]
    fajl.write(rijec)

    if i != len(sve_rijeci) - 1:
        fajl.write("\n")

