def procitaj_prvih_pet():
    ime_fajla = input()
    fajl = open(ime_fajla, "r")

    brojevi = []

    for i in range(5):
        linija = fajl.readline()
        brojevi.append(int(linija))

    print(brojevi)

procitaj_prvih_pet()
