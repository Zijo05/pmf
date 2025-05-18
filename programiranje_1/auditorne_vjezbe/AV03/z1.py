n = int(input("Unesite cijeli broj: "))

ostatak = n % 2
if ostatak == 0:
    print("Broj je paran!")
else:  #moze i elif ostatak == 1:
    print("Broj je neparan!")