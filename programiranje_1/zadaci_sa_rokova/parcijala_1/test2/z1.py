from math import radians, cos, sqrt

a = float(input())
b = float(input())
c = float(input())
d = float(input())

alpha = radians(float(input()))
gamma = radians(float(input()))

s = (a + b + c + d) / 2

P = ((s - a) * (s - b) * (s - c) * (s - d) - a * b * c * d * cos(((alpha + gamma) / 2)) ** 2) ** (1/2)

print(round(P, 2))
