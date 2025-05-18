def is_fin(n):
    n = str(n)
    for x in range(len(n) - 1):
        if int(n[x]) + int(n[x + 1]) == 4:
            return True
    return False
        
n = int(input())

broj = 1

while n > 1:
    if is_fin(broj):
        n -= 1
    broj += 1

print(broj)