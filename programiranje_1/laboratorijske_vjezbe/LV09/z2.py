def pomjeri_udesno(l):
    lista_bez_prvog = l[1:]
    lista_bez_prvog.append(l[0])

    print(lista_bez_prvog)
    return lista_bez_prvog

pomjeri_udesno([1, 2, 3, 4, 5])
