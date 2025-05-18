# 28 14 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

def collatzova_hipoteza(n):
    trenutni = n
    brojac = 1

    while trenutni != 1:
        print(trenutni, end=" ")
        if trenutni % 2 == 0:
            trenutni /= 2
        else:
            trenutni = 3 * trenutni + 1
        brojac += 1
    print()
    return brojac

n = int(input())
print(f"Indeks 1: {collatzova_hipoteza(n)}")