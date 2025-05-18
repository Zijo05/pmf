lista = []

while True:
    s = input()
    if not s:
        break
    lista.append(s)

# print(lista)
for s in lista:
    if not s.startswith("b"):
        print(s, end=" ")