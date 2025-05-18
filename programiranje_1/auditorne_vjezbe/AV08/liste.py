lista = [1, 2, 3, 4]
print(lista)
print(len(lista))
print(max(lista))
print(min(lista))

lista.append("nesto")
print(lista)

print(lista[0])
print(lista[1])

lista[0] = 50
print(lista)

for i in range(len(lista)):
    print(f"Element na indeksu {i} je {lista[i]}")

for element in lista:
    print(f"Element: {element}")


# count
lista = [1,1,2,3,4,1,2,1]
print("Broj jedinica: ", lista.count(1))

# sort
lista = sorted(lista)
print(lista)

lista = sorted(lista, reverse=True)
print(lista)

# spajanje
l1 = [1,2,3]
l2 = [4,5,6]
l = l1 + l2
print(l)

# da li se element nalazi u listi (in operator)
print(2 in l)
print(10 in l)
print(10 not in l)

# negativni indeksi
print(l[-1])
print(l[-2])

# split (string u listu)
s = "1, 2, 3, 4"
l_str = s.split(", ")
print(l_str)
l_int = []
for el in l_str:
    l_int.append(int(el))
print(l_int)
