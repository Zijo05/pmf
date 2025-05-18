def izbroji_rijeci(s):
    rijeci = s.split(" ")
    rjecnik = {}

    # I nacin sa count
    for r in rijeci:
        rjecnik[r] = rijeci.count(r)

    # II nacin
    # for r in rijeci:
    #     if r not in rjecnik:
    #         rjecnik[r] = 1
    #     else:
    #         rjecnik[r] += 1

    print(rjecnik)
    return rjecnik
izbroji_rijeci("neka recenica recenica neka i tako dalje")
