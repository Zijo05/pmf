def suma_prvih_n_kvadrata(n):
    if n == 1:
        return 1

    return suma_prvih_n_kvadrata(n-1) + n ** 2

# 1 + 4 + 9 + 16 = 30
print(suma_prvih_n_kvadrata(4))