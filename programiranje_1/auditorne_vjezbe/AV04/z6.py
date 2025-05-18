n = int(input("n: "))

prost = True
if n == 1:
    prost = False

for i in range(2, n):
    if n % i == 0:
        prost = False
        break

if prost:
    print("Broj je prost!")
else:
    print("Broj nije prost!")
