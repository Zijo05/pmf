import copy

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
max_suma = matrica[0]

for red in matrica:
    if sum(red) > sum(max_suma):
        max_suma = red

# transpozicija matrice
# I nacin: radi za sve matrice
# kolone = []
#
# for i in range(dimenzija): # i je indeks za red
#     for j in range(dimenzija): # j je indeks za kolonu
#         # kolone[j][i] = matrica[i][j]
#         if i == 0:
#             kolone.append([])
#         kolone[j].append(matrica[i][j])
#         # print(f"{i}, {j}", kolone)

# II nacin: radi samo za kvadratne matrice
kolone = copy.deepcopy(matrica)
for i in range(dimenzija): # i je indeks za red
    for j in range(dimenzija): # j je indeks za kolonu
        kolone[j][i] = matrica[i][j]

print(kolone)


for kol in kolone:
    if sum(kol) > sum(max_suma):
        max_suma = kol

print(f"Red sa max sumom: {max_suma}")