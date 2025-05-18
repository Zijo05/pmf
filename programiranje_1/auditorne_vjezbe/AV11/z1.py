


def faktorijel(n):
    print(f"Pozivam funkciju za n={n}")
    if n == 1:
        return 1
    if n == 2:
        return 2

    return n * faktorijel(n-1)

print(faktorijel(6))