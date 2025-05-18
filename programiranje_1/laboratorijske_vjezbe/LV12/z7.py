def unija_listi(dupla_lista):

    # dupla_lista = [ [1,2,3], [4,5,10], [2, 4, 7] ]
    # unija = [1,2,3,4,5,10,7]

    unija = set()

    for lista in dupla_lista:
        unija = unija.union(set(lista))

    return list(unija)

print(unija_listi([ [1,2,3], [4,5,10], [2, 4, 7] ]))

