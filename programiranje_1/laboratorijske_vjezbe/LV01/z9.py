a = float(input("a: "))
b = float(input("b: "))

brojnik = a + b
nazivnik = 1 + (a**2 + b**2) / (a**2 - b**2)

rezultat = brojnik / nazivnik

print(f"Rezultat: {rezultat}")