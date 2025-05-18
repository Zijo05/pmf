def treci_najveci(l):
    s = set(l)
    nova_l = list(s)
    print(nova_l) # sortirani i izbrisani duplikati
    return nova_l[-3]

print(treci_najveci([1,2,3,3,2,4,4]))
