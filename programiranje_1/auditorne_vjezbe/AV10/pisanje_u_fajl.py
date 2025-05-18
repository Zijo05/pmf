fajl = open("fajlovi/primjer1.txt", "w")

fajl.write("Ovo je prva recenica.\n")
fajl.write("Ovo je druga recenica.\n")

linije = ["Prva linija.\n", "Druga linija.\n", str(10)]
fajl.writelines(linije)

fajl.close()