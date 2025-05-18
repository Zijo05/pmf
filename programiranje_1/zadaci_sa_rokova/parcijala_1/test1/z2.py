n = int(input())

recenica = "Najbolji"

broj_djeljivih = 0

if n % 1 == 0:
    recenica += ", najsjajniji"
    broj_djeljivih += 1
if n % 2 == 0:
    recenica += ", najuzbudljiviji"
    broj_djeljivih += 1
if n % 3 == 0:
    recenica += ", najfantasticniji"
    broj_djeljivih += 1
if n % 4 == 0:
    recenica += ", najkrasniji"
    broj_djeljivih += 1
if n % 5 == 0:
    recenica += ", najljepsi"
    broj_djeljivih += 1
if n % 6 == 0:
    recenica += ", najemotivniji"
    broj_djeljivih += 1
if n % 7 == 0:
    recenica += ", najsrdacniji"
    broj_djeljivih += 1
if n % 8 == 0:
    recenica += ", najfiniji"
    broj_djeljivih += 1
if n % 9 == 0:
    recenica += ", najjasniji"
    broj_djeljivih += 1
if n % 10 == 0:
    recenica += ", najinspirativniji"
    broj_djeljivih += 1
    
print(f"{recenica} broj je {n}!")
print(broj_djeljivih)