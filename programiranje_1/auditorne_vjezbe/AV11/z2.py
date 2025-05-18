# [12, 6, 8, 2, 1, 3, 4, 8, 6]
# 12 i [6, 8, 2, 1, 3, 4, 8, 6]
def najveci_paran_u_listi(lista):
    print(f"Pozivam funkciju za: {lista}")
    if lista == []:
        return 0

    prvi = lista[0]

    preostala_lista = lista[1:]
    najveci_u_preostaloj = najveci_paran_u_listi(preostala_lista)

    if prvi % 2 == 0 and prvi > najveci_u_preostaloj:
        return prvi
    else:
        return najveci_u_preostaloj

print(najveci_paran_u_listi([6, 8, 2, 1, 12, 3, 4, 8, 6]))