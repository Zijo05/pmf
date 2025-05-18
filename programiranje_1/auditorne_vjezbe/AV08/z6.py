def najveci_broj_od_cifara(cifre):
    cifre.sort(reverse=True)

    # I nacin preko brojeva
    broj = 0
    # cifre = [5, 4, 3, 2, 2, 1]
    for c in cifre:
        broj = broj * 10 + c

    # II nacin preko stringa
    # broj = ""
    # for c in cifre:
    #     broj += str(c)
    # broj = int(broj)

    return broj

print(najveci_broj_od_cifara([2, 2, 3, 1, 4, 5]))