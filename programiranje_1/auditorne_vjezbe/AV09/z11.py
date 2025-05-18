def cenzurisi(a, b):
    return a.replace(b, "*" * len(b))

a = "Studiram na PMF-u i PMF je super fakultet."
b = "PMF"

print(cenzurisi(a, b))