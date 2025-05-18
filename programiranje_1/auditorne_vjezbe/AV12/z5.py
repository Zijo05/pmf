def anagrami(lista_rijeci):
    rjecnik = {}

    for rijec in lista_rijeci:
        # kljuc je rijec sortirana abecedno
        kljuc = "".join(sorted(rijec))

        if kljuc in rjecnik:
            rjecnik[kljuc] += 1
        else:
            rjecnik[kljuc] = 1

    print(rjecnik)

anagrami(["vatra", "KRASANJEODMOR", "JADRANSKOMORE", "trava", "vrata"])