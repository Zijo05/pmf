import random

a = int(input("a: "))
b = int(input("b: "))

broj = random.randint(a, b)

while True:
    unos = int(input("Unesite broj: "))
    if unos == broj:
        print("Bravo, pogodili ste!")
        break
    elif unos < broj:
        print("Probajte unijeti veci broj!")
    else:
        print("Probajte unijeti manji broj!")
