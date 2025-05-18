def string_u_listu(s):
    return list(s)

def listu_u_string(l, s=""):
    return s.join(l)

s = "neki string"
l = string_u_listu(s)
print(l)
novi_s = listu_u_string(l, "__")
print(novi_s)