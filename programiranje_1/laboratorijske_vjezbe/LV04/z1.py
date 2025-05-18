n = 0
zbir = 0

# I nacin
while n != -1:
    n = int(input("Unesite broj: "))
    if n != -1:
        zbir += n % 10

print("Zbir posljednjih cifara je: ", zbir)

# II nacin
zbir = 0
while True:
    n = int(input("Unesite broj: "))
    if n == -1:
        break
    zbir += n % 10
print("Zbir posljednjih cifara je: ", zbir)


