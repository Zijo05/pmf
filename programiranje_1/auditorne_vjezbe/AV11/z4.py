# Hanoi

# sa_stapa, na_stap su neki od brojeva 1,2,3
def hanoi_kule(n, sa_stapa, na_stap):
    if n == 1:
        print(f"Prebaci disk sa {sa_stapa}. stapa na {na_stap}. stap")
        return
    stapovi = [sa_stapa, na_stap]
    if 1 not in stapovi:
        treci_stap = 1
    elif 2 not in stapovi:
        treci_stap = 2
    else:
        treci_stap = 3

    hanoi_kule(n-1, sa_stapa, treci_stap)
    print(f"Prebaci disk sa {sa_stapa}. stapa na {na_stap}. stap")
    hanoi_kule(n-1, treci_stap, na_stap)

    return

hanoi_kule(3, 1, 2)
# n   0     0
# 1   0     n-1
# 0   1     n-1
# 0   n     0