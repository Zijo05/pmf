def NZD(a, b):
    manji = min(a, b)

    for i in range(manji, 0, -1):
        if a % i == 0 and b % i == 0:
            return i

a = int(input())
b = int(input())

print(NZD(a, b))
