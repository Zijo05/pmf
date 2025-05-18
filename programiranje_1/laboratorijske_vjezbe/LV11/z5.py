# "abcdef"
# a     fedcba

def obrnuti_string(s):

    if len(s) == 0 or len(s) == 1:
        return s

    prvo = s[0]
    ostatak = s[1:]

    obrnuti_ost = obrnuti_string(ostatak)

    return obrnuti_ost + prvo

print(obrnuti_string("abcdef"))
