def palindrom(s: str):
    for karakter in s:
        if not karakter.isalpha():
           s = s.replace(karakter, "")

    s = s.lower()
    print(s)
    return s == s[::-1]

print(palindrom("Ana voli Milovana!!!!!...."))
