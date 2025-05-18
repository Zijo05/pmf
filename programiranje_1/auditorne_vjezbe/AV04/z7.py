n = int(input("n: "))

for i in range(n):
    broj_razmaka = n - i - 1
    broj_zvjz = i + 1
    s = "* "
    print(" " * broj_razmaka + s * (broj_zvjz - 1) + "*")