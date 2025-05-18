def f(rijec):
    rijec = rijec.lower()

    slovo = ""
    duzina = 0

    while(rijec != ""):
        slovo = rijec[0]
        duzina = len(rijec)
        rijec = rijec.replace(slovo, "")

    print(f"Zadnje slovo je {slovo}, broj pojavljivanja {duzina}")

f("tiRurirU")

