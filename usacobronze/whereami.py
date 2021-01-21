with open("whereami.in","r") as fin:
    k,s=fin.readlines()
k,s=int(k),s[:-1]
def ct(targ:str,tlen):
    # counts how many occurrences a substring occurs in a string.
    # hey! This looks like str.count(). But it's not. For example, "aaa".count("aa") gives 1. I want it to give 2
    # because that's what I need. If a substring appears more than once, then it's not unique and we need to bump up
    # the total length by 1.
    return sum(s[letter:letter + tlen] == targ for letter in range(k))
for x in range(1,k+2): # length of the unique substring
    is1 = True
    for y in range(k-x):
        if ct(s[y:y+x],x)!=1:
            is1=False
            break
    if is1:
        break
with open("whereami.out","w") as fout:
    fout.write(str(x))
