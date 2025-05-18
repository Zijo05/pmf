def veci_broj(n1, n2):
    if n1 > n2:
        return n1
    #else:
    return n2

a = float(input())
b = float(input())

br = veci_broj(a, b)
print("Veci broj je", br)