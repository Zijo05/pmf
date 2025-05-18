def da_li_je_prost(n):
    if n == 0:
        return False
    
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

def proste_cifre(n):
    while n != 0:
        cifra = n % 10
        if da_li_je_prost(cifra):
            print(cifra)
        n //= 10

n = int(input())
proste_cifre(n)