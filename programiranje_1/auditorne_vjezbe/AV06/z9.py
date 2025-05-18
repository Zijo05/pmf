poz1, n1 = input().split(" ")
poz2, n2 = input().split(" ")
poz3, n3 = input().split(" ")

poz1 = int(poz1)
n1 = int(n1)
poz2 = int(poz2)
n2 = int(n2)
poz3 = int(poz3)
n3 = int(n3)

cilj = int(input())

while True:
    poz1 += n1
    if poz1 >= cilj:
        break

    poz2 += n2
    if poz2 >= cilj:
        break

    poz3 += n3
    if poz3 >= cilj:
        break

duzina = max(poz1, poz2, poz3)

for i in range(1, duzina+1):
    if i == poz1:
        print("*", end="")
    elif i == cilj:
        print("|", end="")
    else:
        print("_", end="")

print()
for i in range(1, duzina+1):
    if i == poz2:
        print("*", end="")
    elif i == cilj:
        print("|", end="")
    else:
        print("_", end="")

print()
for i in range(1, duzina+1):
    if i == poz3:
        print("*", end="")
    elif i == cilj:
        print("|", end="")
    else:
        print("_", end="")
