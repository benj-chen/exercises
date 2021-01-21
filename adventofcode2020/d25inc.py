with open("i25","r") as fin:
    pc,pd=map(int,fin.readlines())
print(pc,pd)
# get the key, transform it to the other
def t(s,n):
    v=1
    for x in range(n):
        v=(v*s)%20201227
    return v
def trt(pk):
    for x in range(1,max(pc,pd)):
        if t(7,x)==pk:
            return x

cloop=trt(pc)
print(cloop)
print(pd)
print(t(pd,cloop))