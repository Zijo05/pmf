def max_pojavljivanje(lista):
    broj_pojavljivanja = 0
    broj = 0

    for el in lista:
        brojac = lista.count(el)
        if brojac > broj_pojavljivanja:
            broj_pojavljivanja = brojac
            broj = el

    print(f"Broj sa najvise pojavljivanja ({broj_pojavljivanja}) je: {broj}")

    return broj

max_pojavljivanje([2, 3, 1, 2, 2, 3, 3, 4, 3, 2, 3, 1, 3])
