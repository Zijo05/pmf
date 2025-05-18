def prost(n):
    if n == 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

def najveci_prost_djelioc(a, b):
    manji = min(a, b)

    for i in range(manji, 0, -1):
        if prost(i) and a % i == 0 and b % i == 0:
            return i

    return None

a = int(input())
b = int(input())

print(najveci_prost_djelioc(a, b))
