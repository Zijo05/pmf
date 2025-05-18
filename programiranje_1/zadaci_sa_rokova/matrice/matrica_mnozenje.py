A = [[1,2,3],[4,5,6]]
B = [[7,8,9,10],[11,12,13,14],[15,16,17,18]]

C = list()

for i in range(len(A)):
    row = list()
    for j in range(len(B[0])):
        suma = 0
        for k in range(len(B)):
            suma += A[i][k] * B[k][j]
        row.append(suma)
    C.append(row)
    
print(C)