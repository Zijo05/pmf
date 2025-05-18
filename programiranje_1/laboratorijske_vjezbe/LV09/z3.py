def f(lista_rijeci, s):
    brojac = 0
    for rijec in lista_rijeci:
        if rijec.endswith(s):
            brojac += 1

    return brojac
print(f(["asda!", "asdasda.!", "asda.", ".!"], ".!"))
