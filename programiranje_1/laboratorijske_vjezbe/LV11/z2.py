# za n >= k, n i k su >=0
def binomni_koeficijent(n, k):
    if k == 0:
        return 1
    if n == 0:
        return 0
    return binomni_koeficijent(n-1, k-1) + binomni_koeficijent(n-1, k)

print(binomni_koeficijent(10, 4))
