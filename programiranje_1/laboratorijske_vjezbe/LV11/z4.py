

def permutacije(lista):
    if len(lista) == 1:
        return [lista]

    prvi = lista[0]
    ostatak = lista[1:]

    rezultat = []

    perm_ost = permutacije(ostatak)
    # print(f"Permutacije ostatak: {perm_ost}")
    for perm in perm_ost:
        # perm = [1, 2]
        for i in range(len(perm) + 1):
            perm.insert(i, prvi)
            # print(f"Nakon dodavanja na pozicji {i}: {perm}")
            rezultat.append(perm.copy())
            del perm[i]

    return rezultat

sve_p = permutacije([4, 3, 2, 1])
print(len(sve_p))
for p in sve_p:
    print(p)

