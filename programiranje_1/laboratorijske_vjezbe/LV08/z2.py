def rastuca_lista(lista):
    return lista == sorted(lista)

def rastuca_lista_petlja(lista):
    for i in range(len(lista)-1):
        if lista[i] > lista[i+1]:
            return False

    return True

l1 = [-1.2, 1, 2, 2.5, 2.5, 3, 4.5]
print(rastuca_lista(l1))
print(rastuca_lista_petlja(l1))
