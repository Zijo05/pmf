zbir = 0
proizvod = 1

n = float(input("n: "))

while(n >= 0):
    zbir += n
    proizvod *= n
    n = float(input("n: "))

print(f"Zbir je: {zbir}")
print(f"Proizvod je: {proizvod}")

