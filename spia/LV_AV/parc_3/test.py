neki_string = input()

brojaca = 0
brojace = 0
brojaci = 0
brojaco = 0
brojacu = 0

for slovo in neki_string:
    slovo = slovo.lower()
    if slovo == "a":
        brojaca += 1
    elif slovo == "e":
        brojace += 1
    elif slovo == "i":
        brojaci += 1
    elif slovo == "o":
        brojaco += 1
    elif slovo == "u":
        brojacu += 1
        
najponavljanije = max(brojaca, brojace, brojaci, brojaco, brojacu)
if brojaca == najponavljanije:
    print("a", brojaca, "puta")
elif brojace == najponavljanije:
    print("e", brojace, "puta")
elif brojaci == najponavljanije:
    print("i", brojaci, "puta")
elif brojaco == najponavljanije:
    print("o", brojaco, "puta")
elif brojacu == najponavljanije:
    print("u", brojacu, "puta")
    