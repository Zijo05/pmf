def broj_u_binarno(n):
    binarni = ""
    n = abs(n)

    if n == 0:
        return "0"
    while n != 0:
        ostatak = n % 2
        n //= 2
        binarni = str(ostatak) + binarni

    return binarni

n = 10240
print(n, broj_u_binarno(n), bin(n))
