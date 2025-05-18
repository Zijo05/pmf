def validne_zagrade(zagrade):
    broj_otvorenih = 0
    broj_zatvorenih = 0

    for z in zagrade:
        if z == "(":
            broj_otvorenih += 1
        elif z == ")":
            broj_zatvorenih += 1
            if broj_zatvorenih > broj_otvorenih:
                return False

    if broj_zatvorenih < broj_otvorenih:
        return False

    return True

print(validne_zagrade("(()))(()"))
print(validne_zagrade("(()())((()))"))
print(validne_zagrade("((((())))"))
