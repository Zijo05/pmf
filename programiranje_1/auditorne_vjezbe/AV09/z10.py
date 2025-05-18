sve_rijeci = input()

rijeci = sve_rijeci.split(" ")

print(rijeci)
samoglasnici = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]

for rijec in rijeci:
    for s in samoglasnici:
        rijec = rijec.replace(s, "")
    print(rijec)