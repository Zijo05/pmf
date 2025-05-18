def stepenuj(a, b):
    rezultat = 1

    if a == 0 and b < 0:
        print("0 se ne moze stepenovati na negativan broj!")
        return None

    for i in range(abs(b)):
        rezultat *= a

    if b < 0:
        return 1 / rezultat

    return rezultat

print(stepenuj(0, -2))
#print(pow(0, -2))