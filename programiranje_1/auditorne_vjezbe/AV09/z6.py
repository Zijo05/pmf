def spoji_nizove(niz1, niz2):
    novi_niz = niz1 + niz2
    novi_niz.sort()
    return novi_niz

l1 = [1, 2, 3, 4]
l2 = [2.5, 3.5, 12, 100]
print(spoji_nizove(l1, l2))
