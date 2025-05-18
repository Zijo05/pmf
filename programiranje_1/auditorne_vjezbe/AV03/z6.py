sifra = input("Unesite sifru: ")

# duzina
if len(sifra) < 6:
    print(f"Sifra mora imati bar 6 karaktera!")
else:
    if len(sifra) > 16:
        print(f"Sifra mora imati manje ili jednako 16 karaktera!")
    else:
        if ("!" not in sifra) and ("@" not in sifra) and ("#" not in sifra) and ("$" not in sifra):
            print("Sifra mora sadrzavati neki od karaktera: !@#$")
        else:
            if ("0" not in sifra) and ("1" not in sifra) and ("2" not in sifra) and ("3" not in sifra) and ("4" not in sifra) and ("5" not in sifra) and ("6" not in sifra) and ("7" not in sifra) and ("8" not in sifra) and ("9" not in sifra):
                print("Sifra mora sadrzavati neki broj!")
            else:
                if ("012" in sifra) or ("123" in sifra) or ("234" in sifra) or ("345" in sifra) or ("456" in sifra) or ("567" in sifra) or ("678" in sifra)or ("789" in sifra):
                    print("Sifra ne smije sadrzavati tri uzastopne cifre!")
                else:
                    print("Sifra je sigurna!")