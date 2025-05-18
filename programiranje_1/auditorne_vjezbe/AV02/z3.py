ukupno_sek = int(input("Unesite vrijeme u sekundama: "))

sati = ukupno_sek // 3600
minute = (ukupno_sek - sati * 3600) // 60
sekunde = ukupno_sek - sati * 3600 - minute * 60

print(f"{sati}h {minute}min {sekunde}s")