from math import sin, cos, sqrt, radians
alpha = radians(float(input("Unesite ugao alfa: ")))
n = float(input("Unesite n: "))
k = float(input("Unesite k: "))
h = float(input("Unesite h: "))

izraz = ((2 * k**(2/3) * cos(alpha)) / (sin(alpha) * sqrt(h + n)))

print(f"Vrijednost izraza je: {izraz}")