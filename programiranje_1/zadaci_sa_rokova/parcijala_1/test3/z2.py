# Broj dana u mjesecu
jan = 31
feb = 28
mar = 31
apr = 30
may = 31
jun = 30
jul = 31
aug = 31
sep = 30
oct = 31
nov = 30
dec = 31

# Unos
dan = int(input())
mjesec = int(input())
godina = int(input())
prolazni_dani = int(input())

# Prolazi kroz mjesece dokle god ima još dana za proci
while prolazni_dani != 0:
    # Odredi broj dana u trenutnom mjesecu
    if mjesec == 1:
        dani_u_mjesecu = jan
    elif mjesec == 2:
        dani_u_mjesecu = feb
    elif mjesec == 3:
        dani_u_mjesecu = mar
    elif mjesec == 4:
        dani_u_mjesecu = apr
    elif mjesec == 5:
        dani_u_mjesecu = may
    elif mjesec == 6:
        dani_u_mjesecu = jun
    elif mjesec == 7:
        dani_u_mjesecu = jul
    elif mjesec == 8:
        dani_u_mjesecu = aug
    elif mjesec == 9:
        dani_u_mjesecu = sep
    elif mjesec == 10:
        dani_u_mjesecu = oct
    elif mjesec == 11:
        dani_u_mjesecu = nov
    elif mjesec == 12:
        dani_u_mjesecu = dec

    # Odredi koliko je dana ostalo do kraja mjeseca
    preostali_dani_u_mjesecu = dani_u_mjesecu - dan

    if prolazni_dani > preostali_dani_u_mjesecu:
        # Prelaz na iduci mjesec i reduciranje prolaznih dana
        prolazni_dani -= (preostali_dani_u_mjesecu + 1)
        dan = 1
        mjesec += 1

        # Ako je prosao decembar prebaci se na jaunar i na iducu godinu
        if mjesec > 12:
            mjesec = 1
            godina += 1
    else:
        # Ako je prolaznih dana manje nego preostalih dana u mjesecu saberi
        dan += prolazni_dani
        prolazni_dani = 0

# Ispis krajnjeg datuma
print(f"{dan}. {mjesec}. {godina}.")
