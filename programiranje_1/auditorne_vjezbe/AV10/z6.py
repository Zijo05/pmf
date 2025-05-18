fajl = open("abeceda.txt", "w")

prvi_kod = ord("A")
zadnji_kod = ord("Z")

brojac = 1
for i in range(prvi_kod, zadnji_kod+1):
    slovo = chr(i)
    if i == zadnji_kod:
        fajl.write(f"{brojac}. {slovo}")
    else:
        fajl.write(f"{brojac}. {slovo}\n")
    brojac += 1
