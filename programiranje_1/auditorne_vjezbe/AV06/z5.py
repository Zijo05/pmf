n = int(input())

broj = 1
broj_mjesta = len(str(n ** 2)) + 1

for i in range(n):
    for j in range(n):
        if i % 2 == 0: # brojevi rastu u redu
            print(f"{broj:{broj_mjesta}}", end=" ")
            broj += 1
        else:
            if j == 0:
                broj += n - 1
            print(f"{broj:{broj_mjesta}}", end=" ")
            broj -= 1
            if j == n-1:
                broj += n + 1
    print()

