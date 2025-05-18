a = input("Unesite stranicu 1: ")
b = input("Unesite stranicu 2: ")
c = input("Unesite stranicu 3: ")

najveca_stranica = max(a, b, c)

if najveca_stranica == a:
    if float(a)**2 == float(b)**2 + float(c)**2:
        print("Unesene stranice su stranice pravoglog trougla.")
    else:
        print("Unesene stranice nisu stranice pravouglog trougla.")
elif najveca_stranica == b:
    if float(b)**2 == float(a)**2 + float(c)**2:
        print("Unesene stranice su stranice pravoglog trougla.")
    else:
        print("Unesene stranice nisu stranice pravouglog trougla.")
else:
    if float(c)**2 == float(a)**2 + float(b)**2:
        print("Unesene stranice su stranice pravoglog trougla.")
    else:
        print("Unesene stranice nisu stranice pravouglog trougla.")