def n_ti_najveci_v2(lista, n):
    for i in range(n-1):
        maks = max(lista)
        lista.remove(maks)
    return max(lista)

def n_ti_najveci(lista, n):
    sortirana = sorted(lista, reverse=True)
    return sortirana[n-1]

lista = input()
lista = lista.split(" ")

nova_lista = []
for el in lista:
    nova_lista.append(int(el))

lista = nova_lista

n = int(input())

najveci = max(lista)
n_ti = n_ti_najveci_v2(lista, n)

print(f"Razlika {najveci} - {n_ti} = {najveci-n_ti}")

