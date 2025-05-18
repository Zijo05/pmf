import random
n = int(input("n: "))
random.seed(0)

for i in range(n):
    broj = random.randint(10, 100)
    if i == n-1:
        print(broj, end="")
    else:
        print(broj, end=", ")