n = int(input())

ormarici = [0] * n # 0 predstavlja otvoren

for i in range(1, n+1):
    for indeks_ormarica in range(i-1, n, i):
        if ormarici[indeks_ormarica] == 0:
            ormarici[indeks_ormarica] = 1
        else:
            ormarici[indeks_ormarica] = 0

for ormar in ormarici:
    if ormar == 0:
        print("O", end=" ")
    else:
        print("-", end=" ")