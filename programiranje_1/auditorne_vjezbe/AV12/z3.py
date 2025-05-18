def ucitaj_rijeci_iz_fajla(ime_fajla):
    fajl = open(ime_fajla, "r")
    rijeci = fajl.readlines()

    lista = []
    for r in rijeci:
        lista.append(r.strip())

    return set(lista)

def presjek(rijeci1, rijeci2):
    # I nacin preko petlje
    # lista = []
    # for r in rijeci1:
    #     if r in rijeci2:
    #         lista.append(r)
    # print("Presjek: ", lista)

    skup_presjek = rijeci1.intersection(rijeci2)
    print("Presjek: ", list(skup_presjek))

def unija(rijeci1, rijeci2):
    rezultat = set()
    for r in rijeci1:
        rezultat.add(r)
    for r in rijeci2:
        rezultat.add(r)

    print("Unija: ", list(rezultat))

    skup_unija = rijeci1.union(rijeci2)
    print("Unija: ", list(skup_unija))

def samo_prvi(rijeci1, rijeci2):
    razlika = rijeci1.difference(rijeci2)
    print("Razlika samo prvi: ", razlika)
    return razlika

def samo_drugi(rijeci1, rijeci2):
    razlika = rijeci2.difference(rijeci1)
    print("Razlika samo drugi: ", razlika)
    return razlika

def samo_u_jednom(rijeci1, rijeci2):
    razlika1 = samo_prvi(rijeci1, rijeci2)
    razlika2 = samo_drugi(rijeci1, rijeci2)

    rezultat = razlika1.union(razlika2)
    print("Tacno u jednom: ", rezultat)



rijeci1 = ucitaj_rijeci_iz_fajla("f1")
rijeci2 = ucitaj_rijeci_iz_fajla("f2")

print(rijeci1)
print(rijeci2)

presjek(rijeci1, rijeci2)
unija(rijeci1, rijeci2)
samo_prvi(rijeci1, rijeci2)
samo_drugi(rijeci1, rijeci2)
samo_u_jednom(rijeci1, rijeci2)