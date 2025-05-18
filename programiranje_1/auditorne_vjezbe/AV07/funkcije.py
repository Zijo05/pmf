def zbir(a, b, c=0):
    print(f"Parametri su a={a}, b={b}, c={c}")
    print("Poziva se funkcija!")
    s = a + b + c
    print(s)
    return s
    print("nesto nakon return")

n = zbir(10, 5)
print("poslije funkcije", n)

zbir_tri = zbir(10, 5, -3)
print("poslije funkcije", zbir_tri)