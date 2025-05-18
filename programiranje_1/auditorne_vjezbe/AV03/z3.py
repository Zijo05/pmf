n = int(input("Broj: "))

cetverocifren = (n >= 1000) and (n <= 9999)
print(f"Broj cetverocifren: {cetverocifren}")

# print(max(str(n)))

if cetverocifren:
    c4 = n % 10
    c3 = (n // 10) % 10
    c2 = (n // 100) % 10
    c1 = n // 1000

    max_cifra = c1

    if c2 >= max_cifra:
        max_cifra = c2

    if c3 >= max_cifra:
        max_cifra = c3

    if c4 >= max_cifra:
        max_cifra = c4

    # max_cifra = max(c1, c2, c3, c4)
    print(f"Najveca cifra je: {max_cifra}")