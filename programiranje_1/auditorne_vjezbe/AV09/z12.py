def f(lista, s):
    nova_lista = []

    for el in lista:
        #nova_lista.append(f"{s}{el}")
        nova_lista.append(s + str(el))

    return nova_lista

print(f([1,2,3], "student"))