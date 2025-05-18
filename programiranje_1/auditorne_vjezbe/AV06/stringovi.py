n = 12345
n_str = str(n)

n_str = "ABCDE"
print(n_str[1])

for i in range(len(n_str)):
    print(f"Karakter na poziciji {i} je: {n_str[i]}")

print(n_str[-2])

# ord i chr
print(ord("A"))
print(ord("B"))

print(ord("a"))
print(ord("b"))

print(chr(65 + 3))

# indeksiranje
print(n_str[2:4])

# obrtanje stringa
print(n_str[::-1])

# lower upper
print("a".islower())
print("D".isupper())
print("aasSAFasf!2334".lower())
print("aasSAFasf!2334".upper())
