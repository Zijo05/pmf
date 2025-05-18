n = int(input())
m = int(input())

veci = max(n, m)

while True:
    veci += 1
    if veci % m == 0:
        break

print(veci)