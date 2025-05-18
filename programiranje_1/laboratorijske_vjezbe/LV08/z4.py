def pojavljivanje_max(lista):
    max_el = max(lista)
    print("Max element:", max_el)

    # I nacin preko petlje
    brojac = 0
    for el in lista:
        if el == max_el:
            brojac += 1
    print("I nacin:", brojac)

    # II nacin preko count
    brojac = lista.count(max_el)
    print("II nacin:", brojac)

    return brojac

pojavljivanje_max([2,3,1,3,2.5,3,1,2,3])
