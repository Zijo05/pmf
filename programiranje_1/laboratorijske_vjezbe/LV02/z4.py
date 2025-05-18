import math

a = float(input("a: "))
b = float(input("b: "))

brojnik = (a % b) ** (abs(a))
nazivnik = b ** 2
rezultat = math.floor(brojnik / nazivnik)

print(rezultat)
