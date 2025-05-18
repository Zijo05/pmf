ime_fajla = input()
fajl = open(ime_fajla, "r")

tekst = fajl.read()
tekst = tekst.strip()


tekst = tekst.replace("?", ".")
tekst = tekst.replace("!", ".")

recenice = tekst.split(".")
print(f"Broj recenica: {len(recenice)-1}")
