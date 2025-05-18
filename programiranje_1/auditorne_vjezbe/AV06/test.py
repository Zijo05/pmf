# print("{:>3}".format(0))

n = int(input("n: "))

broj = 1

for i in range(n):
    for j in range(n):
        if i % 2 == 0:
            print("{:>3}".format(broj), end="")
            broj += 1
        else:
            print("{:>3}".format(broj + n - 2 * j - 1), end="")
            broj += 1
    print()
        
