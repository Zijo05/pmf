n = int(input("n: "))

# krov
broj_razmaka_prije = n - 1
broj_razmaka_izmedju = -1

for i in range(n-1):
    if i == 0:
        print(" " * broj_razmaka_prije + "*")
    else:
        print(" " * broj_razmaka_prije + "*" + " " * broj_razmaka_izmedju + "*")
    broj_razmaka_prije -= 1
    broj_razmaka_izmedju += 2

# kvadrat
for i in range(n):
    if i == 0 or i == n-1:
        s = "* "
        print(s * (n-1) + "*")
    else:
        print("*" + " " * (2*n-3) + "*")

