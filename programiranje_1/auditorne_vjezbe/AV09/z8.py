def napravi_izjvestaj(s: str):
    broj_malih_slova = 0
    broj_velikih_slova = 0
    broj_cifara = 0
    broj_razmaka = 0

    for karakter in s:
        # if ord(karakter) >= ord("a") and ord(karakter) <= ord("z"):
        #     broj_malih_slova += 1
        if karakter.isalpha():
            if karakter.islower():
                broj_malih_slova += 1
            else:
                broj_velikih_slova += 1
        elif karakter.isdigit():
            broj_cifara += 1
        elif karakter.isspace():
            broj_razmaka += 1

    print(f"Broj malih slova: {broj_malih_slova}")
    print(f"Broj velikih slova: {broj_velikih_slova}")
    print(f"Broj cifara: {broj_cifara}")
    print(f"Broj razmaka: {broj_razmaka}")

napravi_izjvestaj("Neki STRing  123 ")
