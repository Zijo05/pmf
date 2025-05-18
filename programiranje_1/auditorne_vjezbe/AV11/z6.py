def najveci_u_listi(lista):
    if len(lista) == 1:
        return lista[0]

    prvi = lista[0]
    max_u_preostaloj = najveci_u_listi(lista[1:])

    if prvi > max_u_preostaloj:
        return prvi
    else:
        return max_u_preostaloj

print(najveci_u_listi([3,2,15,6,3,12,5]))