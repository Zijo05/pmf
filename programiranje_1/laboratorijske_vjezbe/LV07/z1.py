def cifre_izmedju(n, a, b):
    manja = min(a, b)
    veca = max(a, b)

    while n != 0:
        cifra = n % 10
        n //= 10

        if cifra > manja and cifra < veca:
            print(cifra)

cifre_izmedju(162346789, 3, 7)
