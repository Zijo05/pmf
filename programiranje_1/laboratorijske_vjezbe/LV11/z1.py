def f(n):
    if n < 1:
        print("Ne valja input!")
        return None

    if n == 1:
        return 1

    return f(n-1) + 1/n

print(f(0))
