fajl = open("matrica.in", "r")

linije = fajl.readlines()
matrica = list()

for row in linije:
    matrica.append(row.strip().split(" "))
    

def rotiraj_matricu(matrica):
    nova_matrica = list()
    while matrica[0]:
        red = list()
        for coordinate in range(len(matrica)):
            red.append(matrica[coordinate].pop(0))
        nova_matrica.append(red)
    return nova_matrica
    
def red(matrica, x, y):
    if element == "0":
        return False
    suma = 0
    for element in matrica[x]:
        if element == "1":
            suma += 1
    if suma > 1:
        return True
    return False
            
def komunicira(matrica, x, y):
    if red(matrica, x,):
        return True
    else:
        matrica = rotiraj_matricu(matrica)
        print(matrica)
        print(y)
        if red(matrica, y):
            return True
    return False
    
for row_index in range(len(matrica)):
    for element_index in range(len(row)):
        if komunicira(matrica, row_index, element_index):
            print("more")
        else: print("nemore")
    print("\n novi \n")


            


