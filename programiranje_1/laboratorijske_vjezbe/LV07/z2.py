def samo_parne(n):
    novi_broj = ""

    while n != 0:
        cifra = n % 10
        n //= 10

        if cifra % 2 == 0:
            novi_broj = str(cifra) + novi_broj

    return int(novi_broj)

def samo_parne_v2(n):
    novi_broj = 0
    broj_cifara = 0

    while n != 0:
        cifra = n % 10
        n //= 10

        if cifra % 2 == 0:
            novi_broj = (10 ** broj_cifara) * cifra + novi_broj
            broj_cifara += 1
    return novi_broj

print(samo_parne(10234))
print(samo_parne_v2(10234))


