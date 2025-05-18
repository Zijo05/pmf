n = int(input("n: "))
maksimum = 0
minimum = 0

for i in range(n):
    broj = float(input("broj: "))
    if i == 0:
        maksimum = broj
        minimum = broj

    if broj > maksimum:
        maksimum = broj

    if broj < minimum:
        minimum = broj

    # Za svrhe debagigranja programa:
    # print("max: ", maksimum)
    # print("min: ", minimum)

print("max: ", maksimum)
print("min: ", minimum)
print("Razlika je", maksimum - minimum)
