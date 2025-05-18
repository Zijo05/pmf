def prvih_n_u_fajl(n):
    fajl = open("f1.txt", "w")

    for i in range(1, n+1):
        #fajl.write(str(i) + "\n")
        if i == n:
            fajl.write(f"{i}")
        else:
            fajl.write(f"{i}\n")

prvih_n_u_fajl(100)