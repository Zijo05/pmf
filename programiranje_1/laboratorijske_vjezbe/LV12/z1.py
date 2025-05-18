def max_vrijednost(r):
    #for kljuc in r:
    #    vr = r[kljuc]
    max_vr = float("-inf")
    kljuc_sa_max = ""

    for kljuc, vr in r.items():
        if vr > max_vr:
            max_vr = vr
            kljuc_sa_max = kljuc

    print(f"Kljuc: {kljuc_sa_max}, vrijednost: {max_vr}")
    return kljuc_sa_max

d = {
    "a": 5,
    "b": 10,
    "c": -3
}

max_vrijednost(d)
