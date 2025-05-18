n = int(input())

dobri_parovi = True
temp = n

while temp != 0:
    # x broj pojavljivanja y-cifre u n
    y = temp % 10
    temp //= 10
    x = temp % 10
    temp //= 10
    
    tempp = n
    broj_pojavljivanja_y = 0
    while tempp != 0:
        if y == tempp % 10:
            broj_pojavljivanja_y += 1
        tempp //= 10
    if broj_pojavljivanja_y != x:
        dobri_parovi = False
        break
    
print(dobri_parovi)
    