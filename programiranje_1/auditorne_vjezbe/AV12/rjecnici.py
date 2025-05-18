rjecnik = dict()
# ili
rjecnik = {}

# studenta -> ocjenu
rjecnik["Amir"] = 9
rjecnik["Adisa"] = 7

print(rjecnik)

if "Amir" in rjecnik:
    print(rjecnik["Amir"])

rjecnik["Amir"] = 10
print(rjecnik)

rjecnik["neko"] = [1,2,3]
print(rjecnik)

rjecnik[10] = 20
print(rjecnik)

rjecnik = {"a": 2, "b": 3, "c": 10}
for kljuc in rjecnik:
    print(kljuc)
    vrijednost = rjecnik[kljuc]

print(rjecnik)

del rjecnik["b"]
print(rjecnik)