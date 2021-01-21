with open("i25","r") as fin:
    pc,pd=map(int,fin.readlines())
print(pc,pd)
# get the key, transform it to the other
def ceildiv(x,y):
    xy=x//y # bit shift timesaving LETS GOOOOOOO
    return xy+bool(x%y)
def t(s,n):
    return ceildiv(s**n,ceildiv(s**n,20201227))
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
