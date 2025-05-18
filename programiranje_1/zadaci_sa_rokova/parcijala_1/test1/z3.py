n = int(input())

matrica = ""

h_preostalo = 4


brojac_1 = 0

while brojac_1 < n - 1:
    matrica += "- " *  (n - h_preostalo - 1) + "* "
    unos = "H"
    while unos == "H":
        unos = input()
        if unos == "H":
            matrica += "* "
            h_preostalo -= 1
    matrica += "- " * h_preostalo + "\n"
    brojac_1 += 1
    
    if brojac_1 == 4:
        matrica += "- " *  (n - h_preostalo - 1) + "* "
        while h_preostalo != 0:
            unos = input()
            if unos == "H":
                matrica += "* "
                h_preostalo -= 1
    
    
print(matrica)


