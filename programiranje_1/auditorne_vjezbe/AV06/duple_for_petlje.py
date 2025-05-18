# for i in range(10):
#     print("i: ", i)
#     for j in range(5):
#         print("i, j:", i, j)


red = 7
kolone = 6
slovo = "A"

for i in range(red):
    for j in range(kolone):
        print(slovo, end=" ")
        slovo = chr(ord(slovo) + 1)
    print()