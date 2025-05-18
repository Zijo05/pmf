x = float(input("x: "))

if x > 0:
    print("Broj je pozitivan!")
    print("i dalje u if-u")
elif x == 0:  # skracenica za elseif
    print("Broj je nula!")
    print("i dalje u elif-u")
else:
    print("Broj je negativan!")
    print("i dalje u else")

print("KRAJ")


if x == 5:
    print("Broj je pet")

