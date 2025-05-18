# a^b

# 5^6 = 5^5 * 5

def stepenuj(a, b):
    if b == 1:
        return a

    return stepenuj(a, b - 1) * a

print(stepenuj(10, 9))