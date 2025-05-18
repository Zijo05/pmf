def prost(n):
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

def goldbachova_hipoteza(n):
    if n % 2 != 0 or n <= 2:
        print("Unesite paran broj veci od 2!")
        return None

    for i in range(2, n//2 + 1):
        if prost(i) and prost(n-i):
            return i, n-i

    return None

while True:
    n = int(input())
    a, b = goldbachova_hipoteza(n)
    print(f"{a} + {b} = {n}")


