# 0 1 1 2 3 5 8 13 21 ...

def fibonaci(i):
    if i == 0:
        return 0
    if i == 1 or i == 2:
        return 1

    prosli = 0
    trenutni = 1

    for j in range(i-1):
        iduci = prosli + trenutni

        prosli = trenutni
        trenutni = iduci

    return trenutni

for indeks in range(10):
    print(f"{indeks}. Fibonacijev broj je: {fibonaci(indeks)}")

