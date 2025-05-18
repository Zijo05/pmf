x = float(input("x: "))

if x <= 0:
    f = x ** 2
elif x <= 100:
    f = (100 - x) / (x ** 4)
else:
    f = 200

print(f"f({x}) = {f}")

