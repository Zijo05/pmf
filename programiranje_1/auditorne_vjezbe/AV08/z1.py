l = []

while True:
    n = int(input())
    if n != 100:
        l.append(n)
    else:
        break

print("Obrnuti raspored:")
for i in range(len(l)-1, -1, -1):
    print(l[i])
    
for el in l[::-1]:
    print(el)