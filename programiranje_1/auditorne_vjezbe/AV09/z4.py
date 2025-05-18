def sortiraj_parne(lista):
    samo_parni = []
    for broj in lista:
        if broj % 2 == 0:
            samo_parni.append(broj)

    samo_parni.sort()

    # I nacin: sa insert
    # for i in range(len(lista)):
    #     broj = lista[i]
    #     if broj % 2 != 0:
    #         samo_parni.insert(i, broj)

    rezultat = []
    brojac = 0
    for i in range(len(lista)):
        broj = lista[i]

        if broj % 2 != 0:
            rezultat.append(broj)
        else:
            rezultat.append(samo_parni[brojac])
            brojac += 1

    print(rezultat)
    return rezultat

l = [6, 2, 1, 5, 4, 7, 10, 6, 1]

sortirana = [2, 4, 1, 5, 6, 7, 6, 10, 1]

sortiraj_parne(l)
print("Originalna lista: ", l)