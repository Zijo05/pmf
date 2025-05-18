def srednji_broj(lista):
    lista = sorted(lista)
    print(lista)

    n = len(lista)

    if n % 2 == 1:
        return lista[n//2]
    else:
        return lista[n//2 - 1]

l = [1, -1, 0.5, 0.2, -3, 5]
srednji = srednji_broj(l)

print(srednji)