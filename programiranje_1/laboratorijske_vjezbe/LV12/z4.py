def liste_u_rjecnik(kljucevi, vrijednosti):
    r = {}
    n = len(kljucevi)

    for i in range(n):
        k = kljucevi[i]
        v = vrijednosti[i]

        r[k] = v

    print(r)
    return r

liste_u_rjecnik([0,1,2,3,4,0], ["a", "b", "c", "d", "e", "f"])
