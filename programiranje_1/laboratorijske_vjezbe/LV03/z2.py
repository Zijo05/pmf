n = int(input("n: "))

if n >= 100 and n <= 999:
    print("Trocifren je!")

    # I nacin
    c3 = n % 10
    c2 = (n // 10) % 10
    c1 = n // 100
    p = c1 * c2 * c3
    print(f"Proizvod cifara: {p}")

    # II nacin
    n_str = str(n)
    c3 = int(n_str[0])
    c2 = int(n_str[1])
    c1 = int(n_str[2])
    p = c1 * c2 * c3
    print(f"Proizvod cifara: {p}")
else:
    print("Broj nije trocifren!")
