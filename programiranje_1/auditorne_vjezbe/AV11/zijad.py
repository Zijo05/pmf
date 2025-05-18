lista = [100,4,3,261,102,6,2]
max = 0

def rekurzija(lista, broj, max):
    if broj == 1:
        exit()
    
    print(lista)
    if lista[0] % 2 != 0:
        lista.pop(0)
    elif lista[1] % 2 != 0:
        lista.pop(1)
    elif lista[0] > lista[1]:
        max = lista[0]
        lista.pop(1)
    elif lista[0] < lista[1]:
        max = lista[1]
        lista.pop(0)
    else:
        lista.pop(0)
    
    print(max)
    broj -= 1
    rekurzija(lista, broj, max)

rekurzija(lista, len(lista), max)
