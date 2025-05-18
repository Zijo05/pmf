x = float(input("x: "))
op = input("Operacija: ")
y = float(input("y: "))

r = 0
ispravan_unos = True

if op == "+":
    r = x + y
elif op == "-":
    r = x - y
elif op == "/":
    r = x / y
elif op == "*":
    r = x * y
elif op == "mod":
    r = x % y
else:
    print("Nije podrzana operacija!")
    ispravan_unos = False

if ispravan_unos:
    print(f"Rezultat: {r}")
