def racunaj_s(n):
    if n == 1:
        return 1 + 1 / 8
    return racunaj_s(n-1) + n / ((n+1) ** (n+2))

print(racunaj_s(2))