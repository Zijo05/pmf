ime1 = input("Ime 1. studenta: ")
prezime1 = input("Prezime 1. studenta: ")
prosjek1 = float(input("Prosjek 1. studenta: "))
procenat1 = int(input("Procentualni broj bodova 1. studenta: "))

ime2 = input("Ime 2. studenta: ")
prezime2 = input("Prezime 2. studenta: ")
prosjek2 = float(input("Prosjek 2. studenta: "))
procenat2 = int(input("Procentualni broj bodova 2. studenta: "))

#ime3 = input("Ime 3. studenta: ")
#prezime3 = input("Prezime 3. studenta: ")
#prosjek3 = float(input("Prosjek 3. studenta: "))
#procenat3 = int(input("Procentualni broj bodova 3. studenta: "))

razmak = " " * 12
#print("Ime", "Prezime", "Prosjek ocjena", "Broj bodova u %")
print(f"{ime1:12} {prezime1:12} {round(prosjek1, 2):5}", f"{procenat1}%:12")
#print(ime2, prezime2, f"{prosjek2:.2f}", f"{procenat2}%", sep="\t\t")
#print(ime3, prezime3, f"{prosjek3:.2f}", f"{procenat3}%", sep="\t\t")
