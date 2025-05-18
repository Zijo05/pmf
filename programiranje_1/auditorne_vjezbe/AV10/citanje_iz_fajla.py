fajl = open("fajlovi/brojevi.txt", "r")

# read() cita sve iz fajla
# print(fajl.read())

# ucitaj sve linije i spasi u listu
# linije = fajl.readlines()
# print(linije)
#
# brojevi = []
# for l in linije:
#     # print(l.strip())
#     brojevi.append(int(l))
#
# print(brojevi)

# ucitaj jednu po jednu liniju sa petljom
while True:
    linija = fajl.readline()
    print(linija)
    if not linija:
        break