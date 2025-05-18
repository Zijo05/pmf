ime_fajla = input()
fajl = open(ime_fajla, "r")

tekst = fajl.read()

tekst = tekst.replace(" i ", " I ")
tekst = tekst.replace("\ni ", "\nI ")
tekst = tekst.replace(" i\n", " I\n")
tekst = tekst.replace("\ni\n", "\nI\n")


if tekst[0] == "i" and tekst[1] == " ":
    tekst = "I" + tekst[1:]

if tekst[-1] == "i" and tekst[-2] == " ":
    tekst = tekst[0:-1] + "I"

fajl.close()

fajl = open(ime_fajla, "w")
fajl.write(tekst)
