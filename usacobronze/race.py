with open("race.in","r") as fin:
    ins=fin.readlines()
k,n=map(int,ins.pop(0).split())
ins=map(int,ins)
def ceildiv(x,y):
    xy=x//y if y!=2 else x>>1 # bit shift timesaving LETS GOOOOOOO
    return xy+(int(xy!=x/y))
sumrange=lambda i,j: 0 if i>j else (i+j)*(j-i+1)//2 # haha another bit shift timesave

# given a target t, find e such that sum(range(1,e+1)) or sumrange(1,e) is the lowest number >= t.
# binary search ish? add or subtract something
def arithrt(st,targ):
    lb=1
    ub=ceildiv(targ,2)
    while True:
        m=ceildiv(lb+ub,2)
        if m==ub:
            return st+m
        (lb if sumrange(st,st+m)<targ else ub)=m # ub may be the correct answer

fout=open("race.out","w")
for x in ins:
    rk=ceildiv(k-sumrange(1,x-1),2) # this is the distance that cow needs to get.
    if rk<x:
        print(arithrt(1,k),file=fout)
        continue

    l=arithrt(x,rk) # top speed
    # go up to excluding top speed from the targ speed
    print((l-x-1)*2+x+1+ceildiv(k-sumrange(x,l-1)*2-sumrange(1,x-1),l),file=fout)

fout.close()
# line 34 but easier to read:
#     val=sumrange(x,l-1)*2+sumrange(1,x-1)
#     ct=(l-x-1)*2+x+1
#     ct+=ceildiv(k-val,l)
#     print(ct,file=fout)