n = int(input("n: "))

if len(str(n)) == 5:
    print("Petocifren je!")

    n_str = str(n)
    c1, c2, c3, c4, c5 = int(n_str[0]), int(n_str[1]), int(n_str[2]), int(n_str[3]), int(n_str[4])

    min_cifra = min(c1, c2, c3, c4, c5)
    max_cifra = max(c1, c2, c3, c4, c5)

    if max_cifra == c1:
        druga_max_cifra = max(c2, c3, c4, c5)
    elif max_cifra == c2:
        druga_max_cifra = max(c1, c3, c4, c5)
    elif max_cifra == c3:
        druga_max_cifra = max(c1, c2, c4, c5)
    elif max_cifra == c4:
        druga_max_cifra = max(c1, c2, c3, c5)
    elif max_cifra == c5:
        druga_max_cifra = max(c1, c2, c3, c4)

    print(f"Min cifra: {min_cifra}")
    print(f"Druga max cifra: {druga_max_cifra}")
    print(f"Razlika izmedju druge najvece i najmanje cifre je: {druga_max_cifra - min_cifra}")
else:
    print("Nije petocifren!")
