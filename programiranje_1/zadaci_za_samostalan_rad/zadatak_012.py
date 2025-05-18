from math import pi
broj = int(input("Unesite prirodan broj 1-4: "))

if broj == 1:
    r = float(input("Unesite poluprecnik kruga (realan broj): "))
    print(f"Povrsina zadatog kruga: {pi*r**2}")
elif broj == 2:
    a = float(input("Unesi stranicu pravougaonika (a): "))
    b = float(input("Unesi stranicu pravougaonika (b): "))
    print(f"Povrsina zadatog pravougaonika: {a*b}")
    print(f"Obim zadatog pravougaonika: {2 * a + 2 *b}")
elif broj == 3:
    a = float(input("Unesite stranicu kvadrata a: "))
    if a <= 0:
        print("Stranica kvadrata mora biti > 0!")
    else:
        print(f"Povrsina zadatog kvadrata: {a**2}")
elif broj == 4:
    a = int(input("Unesite broj a: "))
    b = int(input("Unesite broj b: "))
    if b < a:
        print(f"Broj a ({a}) je veći.")
    elif a < b:
        print(f"Broj b ({b}) je veći.")
    else:
        print(f"Brojevi a i b ({a} i {b}) su jednaki.")
else:
    print("Slusas li ti mene!")