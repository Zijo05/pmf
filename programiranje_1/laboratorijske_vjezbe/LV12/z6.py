def sadrzi_sve_samoglasnike(s):
    #samoglasnici = set(["a", "e", "i", "o", "u"])
    samoglasnici = {"a", "e", "i", "o", "u"}
    slova_iz_s = set(list(s.lower()))

    presjek = slova_iz_s.intersection(samoglasnici)

    return presjek == samoglasnici

print(sadrzi_sve_samoglasnike("AEio asdjfer dxcb"))
