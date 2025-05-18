import math

r = float(input("Unesite poluprecnik kruznice: "))

# koristimo math.pi za aproksimaciju broja pi
obim = 2 * r * math.pi
povrsina = (r ** 2) * math.pi

print(f"Obim je {round(obim, 3)}")
print("Povrsina je " + str(round(povrsina, 3)))
