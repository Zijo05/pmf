dimenzija = int(input("Dimenzija matrice: "))

matrica = []

for i in range(dimenzija):
    red_str = input(f"Unesite {i+1}. red: ")
    red_str = red_str.split(" ")

    red_int = []

    for el in red_str:
        red_int.append(int(el))

    matrica.append(red_int)

print(matrica)
# max_element = float("-inf")
max_element = max(matrica[0])


for red in matrica:
    max_u_redu = max(red)
    if max_u_redu > max_element:
        max_element = max_u_redu

print(f"Maksimalni element: {max_element}")