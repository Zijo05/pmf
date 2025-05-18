def povrsina_trougla(x1, y1, x2, y2, x3, y3):
    return 1/2 * abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))

def tacka_je_u_trouglu(x1, y1, x2, y2, x3, y3, x4, y4):
    P1 = povrsina_trougla(x1, y1, x2, y2, x4, y4)
    P2 = povrsina_trougla(x1, y1, x3, y3, x4, y4)
    P3 = povrsina_trougla(x2, y2, x3, y3, x4, y4)
    P = povrsina_trougla(x1, y1, x2, y2, x3, y3)
    if abs((P1 + P2 + P3) - P) < 0.000001:
        return True
    return False

def tacke_kolinearne(x1, y1, x2, y2, x3, y3):
    return povrsina_trougla(x1, y1, x2, y2, x3, y3) == 0

x1 = float(input("Unesi T1(x): "))
y1 = float(input("Unesi T1(y): "))
x2 = float(input("Unesi T2(x): "))
y2 = float(input("Unesi T2(y): "))
x3 = float(input("Unesi T3(x): "))
y3 = float(input("Unesi T3(y): "))

if not tacke_kolinearne(x1, y1, x2, y2, x3, y3):
    x4 = float(input("Unesite T4(x): "))
    y4 = float(input("Unesite T4(y): "))
    if tacka_je_u_trouglu(x1, y1, x2, y2, x3, y3, x4, y4):
        print("Tacka je u trouglu (T1, T2, T3)!")
    else:
        print("Tacka nije u trouglu (T1, T2, T3)!")
else:
    print("Tacke su kolinearne, te ne cine trougao!")