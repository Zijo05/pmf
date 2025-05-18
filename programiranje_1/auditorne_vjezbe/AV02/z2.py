import math
a = float(input("Unesite prvu stranicu: "))
b = float(input("Unesite drugu stranicu: "))
degree_sign = u'\N{DEGREE SIGN}'
ugao = float(input(f"Unesite ugao ({degree_sign}): "))

ugao_rad = (ugao * math.pi) / 180

c = math.sqrt(a**2 + b**2 - 2*a*b*math.cos(ugao_rad))


print(f"Treca stranica je {c:.3f}")