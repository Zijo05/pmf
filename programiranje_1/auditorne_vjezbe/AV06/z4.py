n = int(input())

for i in range(n):
    for j in range(n):
        okvir = min(i, j, n-1-i, n-1-j)
        slovo = chr(ord("A") + okvir)
        print(slovo, end=" ")
    print()