fajl = open("rezultati.txt", "r")

linije = fajl.readlines()

print(linije)

ukupno = 0
for l in linije:
    bodovi = l.split(" ")[-1]
    ukupno += float(bodovi)

print(f"Ukupan broj bodova: {ukupno}")
if ukupno < 55:
    print("Ocjena 5")
elif ukupno < 65:
    print("Ocjena 6")
elif ukupno < 75:
    print("Ocjena 7")
elif ukupno < 85:
    print("Ocjena 8")
elif ukupno < 95:
    print("Ocjena 9")
else:
    print("Ocjena 10")