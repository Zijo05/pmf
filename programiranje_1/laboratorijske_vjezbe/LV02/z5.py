a1 = float(input("a1: "))
b1 = float(input("b1: "))
c1 = float(input("c1: "))

a2 = float(input("a2: "))
b2 = float(input("b2: "))
c2 = float(input("c2: "))

y = (a2 * c1 - c2 * a1) / (b2 * a1 - b1 * a2)
x = (-b1*y - c1) / a1

print(f"Rjesenja su x={x} y={y}")
