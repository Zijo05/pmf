def ispisi_koordinate(m):
    n = len(m)
    for i in range(n):
        for j in range(n):
            print(f"({i}, {j})", end=" ")
        print()

def cik_cak(m):
    sve_dijagonale = []
    n = len(m)
    d = 2 * n - 1
    # ispisi_koordinate(m)
    for i in range(n):
        dijagonala = []
        # (0, i), (1, i-1), (2, i-2), ..., (i, 0) koordinate trenutne dijagonale
        for red in range(i+1):
            kolona = i - red
            dijagonala.append(m[red][kolona])
        sve_dijagonale.append(dijagonala)

    for i in range(n, d):
        dijagonala = []
        # (i-(n-1), n-1), (i-(n-1)+1, n-2), ..., (n-1, i-(n-1)) ( koordinate trenutne dijagonale
        for kolona in range(n-1, i-(n-1)-1, -1):
            red = i - kolona
            dijagonala.append(m[red][kolona])
        sve_dijagonale.append(dijagonala)

    for i in range(len(sve_dijagonale)):
        dijagonala = sve_dijagonale[i]
        if i % 2 == 0:
            dijagonala.reverse()
        # print(dijagonala)
        for element in dijagonala:
            print(element, end=" ")


m = [[1, 5, 3, 2],
     [2, 3, 7, 9],
     [7, 10, 8, 1],
     [9, 5, 1, 3]]
print(m)

cik_cak(m)
