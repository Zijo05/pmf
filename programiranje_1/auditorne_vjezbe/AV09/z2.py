lista = []

while True:
    unos = float(input())
    if unos != 0:
        lista.append(unos)
    else:
        break

polovina = lista[len(lista)//2:]
print(max(polovina))