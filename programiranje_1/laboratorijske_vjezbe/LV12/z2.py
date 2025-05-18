def spoji_rjecnike(r1, r2):
    r = r1

    for kljuc, vr in r2.items():
        r[kljuc] = vr

    return r

d1 = {
    "a": 5,
    "b": 10,
    "c": -3
}

d2 = {
    "a": 20,
    "d": 0,
}

print(spoji_rjecnike(d1, d2))
