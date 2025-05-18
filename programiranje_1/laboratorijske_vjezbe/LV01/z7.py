broj_z = int(input("Unesite broj osoba zenskog spola: "))
broj_m = int(input("Unesite broj osoba muskog spola: "))

ukupno = broj_z + broj_m
procenat_z = (broj_z / ukupno) * 100
procenat_m = (broj_m / ukupno) * 100

print("Procentat djevojaka:", round(procenat_z, 2))
print("Procentat muškaraca:", round(procenat_m, 2))

print(int(2.9999)) # otkidanje decimala, pretvaranje float u int
print(int(float("2.999"))) # pretvaranje stringa u float, pa pretvaranja float u int
