g = int(input("Broj godina psa: "))

ljudske_g = 0

if g == 0:
    ljudske_g = 0
elif g == 1:
    ljudske_g = 15
elif g == 2:
    ljudske_g = 15 + 9
elif g >= 3:
    ljudske_g = 15 + 9 + (g - 2) * 5

print(f"Godine psa u ljudskim godinama: {ljudske_g}")