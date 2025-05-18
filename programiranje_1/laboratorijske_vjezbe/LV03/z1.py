bodovi_vjezbe = int(input("Bodovi na vjezbama: "))
bodovi_parcijale = int(input("Bodovi na parcijalama: "))
bodovi_zavrsni = int(input("Bodovi na zavrsnom: "))

ukupno_bodovi = bodovi_vjezbe + bodovi_parcijale + bodovi_zavrsni

ocjena = 0
if ukupno_bodovi < 55:
    ocjena = 5
elif ukupno_bodovi < 65:
    ocjena = 6
elif ukupno_bodovi < 75:
    ocjena = 7
elif ukupno_bodovi < 85:
    ocjena = 8
elif ukupno_bodovi < 95:
    ocjena = 9
else:
    ocjena = 10

print(f"Ukupan broj bodova: {ukupno_bodovi}")
print(f"Ocjena: {ocjena}")
