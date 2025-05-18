fajl = open("tekst.txt", "r")

cijeli_tekst = fajl.read()
cijeli_tekst = cijeli_tekst.replace("\n", " ")
broj_rijeci = len(cijeli_tekst.split(" "))

print("Broj rijeci:", broj_rijeci)