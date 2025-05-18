ukupno_sekunde = int(input("Unesite ugao u sekundama: "))

stepeni = ukupno_sekunde // 3600
minute = (ukupno_sekunde // 60) % 60
sekunde = ukupno_sekunde - stepeni * 3600 - minute * 60

print(f"Ugao: {stepeni}° {minute}' {sekunde}''")


provjera = sekunde + minute * 60 + stepeni * 3600
print(f"{ukupno_sekunde} = {provjera}")
