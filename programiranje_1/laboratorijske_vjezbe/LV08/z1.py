lista = []

while True:
    n = float(input())
    if n == 0:
        break
    lista.append(n)

lista.sort()

print("Brojevi u rastucem poretku:")

for el in lista:
    print(el)
