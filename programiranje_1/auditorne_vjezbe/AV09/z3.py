def prost(n):
    if n == 1:
        return False
    if n == 2 or n == 3:
        return True
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

def ima_cifru_pet(n):
    return "5" in str(n)

lista = []
n = int(input())

for i in range(n):
    broj = int(input())
    lista.append(broj)

prosti_sa_pet = []
for broj in lista:
    if prost(broj) and ima_cifru_pet(broj):
        prosti_sa_pet.append(broj)

print(f"Najveci prosti sa 5: {max(prosti_sa_pet)}")