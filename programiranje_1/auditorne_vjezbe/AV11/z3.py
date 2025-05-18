# Fibonaci: 1 1 2 3 5 8 13 ...

def n_ti_fibonacijev(n):
    if n == 1 or n == 2:
        return 1

    return n_ti_fibonacijev(n-1) + n_ti_fibonacijev(n-2)

print(n_ti_fibonacijev(7))