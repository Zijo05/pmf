n = int(input("n: "))
max_cifra = 0

n = abs(n)

while n != 0:
    print("petlja n:", n)
    cifra = n % 10
    if cifra > max_cifra:
        max_cifra = cifra

    n = n // 10
    print("trenutna cifra", cifra)
    print("trenutna max cifra", max_cifra)

print("max cifra", max_cifra)
