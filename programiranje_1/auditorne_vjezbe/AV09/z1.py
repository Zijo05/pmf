def prva_zadnja_trecina(lista):
    n = len(lista)
    trecina = n//3

    prva_trecina = lista[0:trecina]
    zadnja_trecina = lista[-trecina:]

    return prva_trecina + zadnja_trecina

lista = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
print(prva_zadnja_trecina(lista))