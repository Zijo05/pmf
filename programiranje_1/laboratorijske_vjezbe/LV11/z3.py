def rastuci_niz(lista):
    if len(lista) == 1:
        return True
    prvi = lista[0]
    ostatak = lista[1:]
    if rastuci_niz(ostatak):
        drugi = ostatak[0]
        if prvi < drugi:
            return True
        else:
            return False
    else:
        return False

print(rastuci_niz([1, 5, 10, 12, 15]))
print(rastuci_niz([7, 5, 12, 15]))
