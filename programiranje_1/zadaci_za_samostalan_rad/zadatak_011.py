broj = input("Unesite 5-cifreni broj: ")

if len(broj) != 5:
    print("Broj nije petocifren!")
elif broj == broj[::-1]:
    print("Broj je palindrom.")
else:
    print("Broj nije palindrom.")