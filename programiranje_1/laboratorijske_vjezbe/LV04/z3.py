import math

n = int(input("n: "))

h = 0
g = 1
a = 0
k = 0

for i in range(n):
    broj = int(input(f"Unesite {i+1}. broj: "))
    a += broj
    g *= broj
    h += 1 / broj
    k += broj ** 2

a /= n
g = g ** (1 / n)
k = math.sqrt(k / n)
h = n / h

print("Aritmeticka sredina: ", a)
print("Geometrijska sredina: ", g)
print("Harmonijska sredina: ", h)
print("Kvadratna sredina: ", k)
