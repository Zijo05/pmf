def palindrom(n):
    n = abs(n)
    return str(n) == str(n)[::-1]

def obrni_broj(n):
    novi = 0

    while n != 0:
        cifra = n % 10
        n //= 10
        novi = novi * 10 + cifra

    return novi

def palindrom_v2(n):
    n = abs(n)
    obrnuti = obrni_broj(n)
    return obrnuti == n


n = int(input())
print(f"n je palindrom: {palindrom(n)}")
print(f"n je palindrom: {palindrom_v2(n)}")
