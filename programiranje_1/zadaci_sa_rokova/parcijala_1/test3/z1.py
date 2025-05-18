n = int(input())

ispis = str()

for _ in range(n):
    unos = int(input())
    if unos != n:
        ispis += str(unos) + "\n"

print(ispis)