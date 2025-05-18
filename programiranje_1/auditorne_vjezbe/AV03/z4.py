a = int(input("a: "))
b = int(input("b: "))
c = int(input("c: "))
d = int(input("d: "))

# (a,b) i (c,d) iste boje ili ne
# if (a % 2 == 0 and b % 2 == 0) or (a % 2 == 1 or b % 2 == 1)
# if (a - b % 2 == 0)
if (a % 2 == b % 2):
    boja1 = 1 # crna
else:
    boja1 = 0 # bijela

if (c % 2 == d % 2):
    boja2 = 1 # crna
else:
    boja2 = 0 # bijela

if (boja1 == boja2):
    print("Polja su iste boje!")
else:
    print("Polja su razlicite boje!")

# 2. nacin
if ((a % 2 == b % 2) and (c % 2 == d % 2)) or ((a % 2 != b % 2) and (c % 2 != d % 2)):
    print("Polja su iste boje!")
else:
    print("Polja su razlicite boje!")