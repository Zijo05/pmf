# 5! = 1 * 2 * 3 * 4 * 5
# 0! = 1

def faktorijel(n):
    if n == 0:
        return 1
    if n < 0:
        print("Faktorijel negativnog broja nije definisan!")
        return -1

    rezultat = 1
    for i in range(1, n+1):
        rezultat *= i

    return rezultat


n = int(input())
print(faktorijel(n))
