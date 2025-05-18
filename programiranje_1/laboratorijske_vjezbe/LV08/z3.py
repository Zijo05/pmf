import random

def f(a, b):
    lista = []

    while len(lista) != 10:
        broj = round(random.uniform(a, b), 2)
        if broj not in lista:
            lista.append(broj)
        else:
            print("ISTI")

    print(len(lista))
    print(lista)
    return lista

f(10, 20)
