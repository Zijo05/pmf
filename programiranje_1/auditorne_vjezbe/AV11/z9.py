def reduciraj_string(s):
    if len(s) == 1:
        return s
    if len(s) == 0:
        return ""

    prvo_slovo = s[0]

    reducirani_ostatak = reduciraj_string(s[1:])

    if prvo_slovo == reducirani_ostatak[0]:
        return reducirani_ostatak
    else:
        return prvo_slovo + reducirani_ostatak

print(reduciraj_string("ffgaaddsbbbccssss"))