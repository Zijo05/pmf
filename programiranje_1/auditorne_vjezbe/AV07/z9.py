def obrni_string(s):
    # return s[::-1]
    rezultat = ""

    for karakter in s:
        rezultat = karakter + rezultat

    return rezultat

s = input()
print(obrni_string(s))