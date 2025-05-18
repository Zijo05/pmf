def pangram2(s):
    s = s.lower()

    slova = {}
    for kod in range(ord("a"), ord("z")+1):
        slova[chr(kod)] = 0

    for karakter in s:
        if karakter in slova:
            slova[karakter] += 1

    for kljuc in slova:
        vrijednost = slova[kljuc]
        if vrijednost == 0:
            print("Nije pangram!")
            return

    print("Jeste pangram!")


def pangram(s):
    s = s.lower()

    sva_slova = set()
    for kod in range(ord("a"), ord("z")+1):
        sva_slova.add(chr(kod))

    slova_iz_stringa = set()
    for karakter in s:
        slova_iz_stringa.add(karakter)

    presjek = sva_slova.intersection(slova_iz_stringa)

    if presjek == sva_slova:
        print("Jeste pangram!")
    else:
        print("Nije pangram!")

pangram2("The uick brown fox jumps over the lazy dog")
pangram2("The quick brown fox jumps over the lazy dog")