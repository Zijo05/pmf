d = int(input("Dan: "))
m = int(input("Mjesec: "))
g = int(input("Godina: "))

zadnji_dan_u_mjesecu = False

broj_dana_u_mjesecu = 0
if m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12:
    broj_dana_u_mjesecu = 31
elif m == 2:  # Februar
    prestupna = False
    if (g % 4 == 0 and g % 100 != 0) or (g % 100 == 0 and g % 400 == 0):
        prestupna = True

    if prestupna:
        broj_dana_u_mjesecu = 29
    else:
        broj_dana_u_mjesecu = 28
else:
    broj_dana_u_mjesecu = 30

if d == broj_dana_u_mjesecu:
    zadnji_dan_u_mjesecu = True

if not zadnji_dan_u_mjesecu:
    d_sljedeci = d + 1
    m_sljedeci = m
    g_sljedeci = g
else:
    d_sljedeci = 1

    if m == 12:
        m_sljedeci = 1
        g_sljedeci = g + 1
    else:
        m_sljedeci = m + 1
        g_sljedeci = g

print(f"Dan.Mjesec.Godina: {d}.{m}.{g}")
print(f"Sljedeci Dan.Mjesec.Godina: {d_sljedeci}.{m_sljedeci}.{g_sljedeci}")
