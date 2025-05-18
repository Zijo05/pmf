for i in [1,2,3,4,5]:
    print(i)
    print("nesto")

for neka_var in ["string1", 2, 4, "string3"]:
    print(neka_var)

n = int(input("n: "))

for i in range(n):
    print(i+1)

for i in range(1, n+1):
    print(i)
    if i == 5:
        break

for i in range(1, n+1):
    if i == 5:
        continue
    print(i)

print("KRAJ")