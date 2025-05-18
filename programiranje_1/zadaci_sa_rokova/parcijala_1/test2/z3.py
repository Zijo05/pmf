n = int(input())

broj = 0
while broj != 1 and broj != 4:
    broj = 0
    while n != 0:
        broj += (n % 10) ** 2
        n //= 10
    n = broj
    
if broj == 1:
    print("dobar")
else:
    print("nije dobar")