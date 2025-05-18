n = int(input())

broj = 10
broj_finih = 0
zadnji_fin_broj = 0

while broj_finih < n:
    # da li je broj fin?
    kopija = broj # kopija jer broju otkidamo cifre
    while broj >= 10:
        zadnja_cifra = broj % 10
        predzadnja_cifra = int(str(broj)[-2])
        if zadnja_cifra + predzadnja_cifra == 4:
            # uvecavamo broj finih i spasavamo fin broj
            broj_finih += 1
            zadnji_fin_broj = kopija
            print(zadnji_fin_broj)
            break
        else:
            broj = broj // 10
    broj = kopija + 1
print(f"{n}. fin broj je: {zadnji_fin_broj}")