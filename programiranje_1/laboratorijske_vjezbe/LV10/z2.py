def samo_slova_brojevi(r):
    rezultat = ""

    for karakter in r:
        if karakter.isalnum():
            rezultat += karakter

    return rezultat

ime_fajla = input()
fajl = open(ime_fajla, "r")

tekst = fajl.read()

rijeci = tekst.split(" ")

for r in rijeci:
    print(samo_slova_brojevi(r))
