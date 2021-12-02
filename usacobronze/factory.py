with open("factory.in","r") as fin:
    ins=[list(map(int,x.split())) for x in fin.readlines()]
n=ins.pop(0)[0]
maps={x:[] for x in range(1,n+1)}
for x in ins:
    maps[x[0]].append(x[1])
base=[x for x in maps if not maps[x]]
def gototarg(targ,start):
    if start==targ:
        return True
    for x in maps[start]:
        if gototarg(targ,x):
            return True
    return False
res=-1
for x in base:
    works=True
    for y in maps:
        if not gototarg(x,y):
            works=False
            break
    if works:
        res=x
        break

with open('factory.out','w') as fout:
    fout.write(str(res))

# time 29:03.78 min:sec.ms