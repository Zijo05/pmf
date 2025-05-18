zbir = 0
proizvod = 1

while(True):
    n = float(input("n: "))
    if n < 0:
        break
    zbir += n
    proizvod *= n

print(f"Zbir je: {zbir}")
print(f"Proizvod je: {proizvod}")

