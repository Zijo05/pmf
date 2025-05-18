n = int(input("n: "))

for i in range(n):
    if i == 0 or i == n-1:
        # prvi i zadnji red
        s1 = "* "
        print(s1 * (n-1) + "*")
    else:
        # negdje u sredini
        print("*" + " " * (2*n-3) + "*")