n = int(input("Unesite trocifren broj: "))

c3 = n % 10
c2 = (n // 10) % 10
c1 = n // 100

if (abs(c3 - c2) == 1) or (abs(c3 - c1) == 1) or (abs(c2 - c1) == 1):
    print("Neke dvije cifre razlikuju se za 1!")
else:
    print("Nikoje dvije cifre se ne razlikuju za 1!")