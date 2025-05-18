def palindrom(l):
    return l == l[::-1]

def f(matrica):
    svi_redovi_palindromi = True
    sve_kolone_palindromi = True

    for red in matrica:
        if not palindrom(red):
            svi_redovi_palindromi = False
            break

    broj_redova = len(matrica)
    broj_kolona = len(matrica[0])

    for j in range(broj_kolona):
        kolona = []
        for i in range(broj_redova):
            kolona.append(matrica[i][j])
        if not palindrom(kolona):
            sve_kolone_palindromi = False
            break

    if svi_redovi_palindromi and sve_kolone_palindromi:
        print("savrsena")
    elif not svi_redovi_palindromi and not sve_kolone_palindromi:
        print("nesavrsena")
    else:
        print("polusavrsena")

f([[1, 2, 1], [3, 4, 3], [1, 2, 1]])
f([[1, 2, 1], [3, 4, 3], [5, 6, 5]])
f([[1, 2, 1], [3, 4, 3], [1, 2, 3]])
