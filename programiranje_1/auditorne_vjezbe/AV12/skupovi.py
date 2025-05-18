skup = set()

skup.add(1)
skup.add(2)
skup.add(3)
skup.add(1)

skup = set([4,4,3,2,3,1,2,3,2])

print(skup)

for el in skup:
    print(el)

lista = [1,2,3,1,2,1,2,3]
lista_bez_duplikata = list(set(lista))
print(lista_bez_duplikata)

print(skup)
skup.pop()
print(skup)

#skup.remove(10)
print(skup)

print(2 in skup)