import math


def f(x, y):
    if x < -5:
        return x + y
    if x < 0:
        return pow(x, y) # x ** y
    if x < 10:
        return pow(x, pow(y, x)) # x ** (y ** x)
    if x < 15:
        return math.factorial(x)
    return 0

print(f(3, 2))