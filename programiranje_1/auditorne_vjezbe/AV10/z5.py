def ucitaj_brojeve(fajl):
    brojevi = []
    linije = fajl.readlines()

    for l in linije:
        brojevi.append(int(l))

    return brojevi

fajl1 = open("f1.txt", "r")
fajl2 = open("f3.txt", "r")

brojevi1 = ucitaj_brojeve(fajl1)
brojevi2 = ucitaj_brojeve(fajl2)

print(brojevi1)
print(brojevi2)

zbir = sum(brojevi1) + sum(brojevi2)

fajl2.close()

fajl2 = open("f3.txt", "w")
for i in range(len(brojevi2)):
    if i == 2:
        fajl2.write(f"{zbir}\n")
    fajl2.write(f"{brojevi2[i]}\n")


