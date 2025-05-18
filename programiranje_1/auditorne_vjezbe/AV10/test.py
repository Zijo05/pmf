lista = list()

for _ in range(3):
    lista.append(list())
    
string = "ispitjeupetak"

counter = 0
asc = True
for i in range(len(string)):
    for j in range(3):
        if j == counter:
            lista[j].append(f" {string[i]} ")
        else:
            lista[j].append(" _ ")
    if counter == 2 and asc == True:
        asc = False
    elif counter == 0 and asc == False:
        asc = True
    if asc:
        counter += 1
    else:
        counter -= 1

for x in lista:
    print(x)