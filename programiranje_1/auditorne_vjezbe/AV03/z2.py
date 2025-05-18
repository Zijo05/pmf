x = int(input("x: "))
y = int(input("y: "))
z = int(input("z: "))

# 1. nacin
if x == y and y == z:
    print("Svi su jednaki!")
elif x == y and y != z:
    print("Dva su jednaka!")
elif x == z and y != x:
    print("Dva su jednaka!")
elif y == z and x != y:
    print("Dva su jednaka!")
else:
    print("Svi su razliciti!")

# 2. nacin
if x == y and y == z:
    print("Svi su jednaki!")
elif (x == y and y != z) or (x == z and y != x) or (y == z and x != y):
    print("Dva su jednaka!")
else:
    print("Svi su razliciti!")

# 3. nacin
if x == y and y == z:
    print("Svi su jednaki!")
elif x != y and y != z and x != z:
    print("Svi su razliciti!")
else:
    print("Dva su jednaka!")