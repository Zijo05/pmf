# Unos prvog vremena
print("Unesite vrijeme 1 (h min sec):")
h1 = int(input("Sati: "))
m1 = int(input("Minute: "))
s1 = int(input("Sekunde: "))

# Unos drugog vremena
print("Unesite vrijeme 2 (h min sec):")
h2 = int(input("Sati: "))
m2 = int(input("Minute: "))
s2 = int(input("Sekunde: "))

# Preračunaj oba vremena u sekunde
time1_seconds = h1 * 3600 + m1 * 60 + s1
time2_seconds = h2 * 3600 + m2 * 60 + s2

# Izračunaj razliku u sekundama
difference_seconds = time2_seconds - time1_seconds

# Preračunaj razliku u sate, minute i sekunde
hours = difference_seconds // 3600
remaining_seconds = difference_seconds % 3600
minutes = remaining_seconds // 60
seconds = remaining_seconds % 60

# Ispis rezultata
print("\nIzmeđu ova dva trenutka je proteklo:")
print(f"{hours} h {minutes} min i {seconds} sec.")
