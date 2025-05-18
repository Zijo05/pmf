lista = [100,4,3,260,5,6,2]
max = 0

def rekurzija(lista, broj, max):
    a=0
    if broj == 1:
        exit()
    sad = lista[a]
    
    print(lista)
    
    if sad > lista[a+1]:
        max = sad
        lista.pop(lista.index(lista[a+1]))
    elif sad < lista[a+1]:
        max = lista[a+1]
        lista.pop(lista.index(sad))
    
    print(max)
    broj -= 1
    rekurzija(lista, broj, max)

rekurzija(lista, len(lista), max)
