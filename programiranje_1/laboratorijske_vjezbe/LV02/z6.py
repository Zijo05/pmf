a = float(input("a: "))
b = float(input("b: "))
c = float(input("c: "))


r1 = abs(a+b-c)
r2 = abs(a-b+c)
r3 = abs(-a+b+c)

rezultat = (r1 + r2 + r3) / 3

print(f"Rezultat: {rezultat:.2f}")
