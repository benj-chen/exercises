with open("photo.in","r") as fin:
    n,a=[list(map(int,x.split())) for x in fin.readlines()]

n=range(1,n[0]+1)
asum=sum(a)
nsum=sum(n)*2
# try taking out one at a time per one at a time
posstakeout=set()
for x in n:
    for y in n:
        if y==x: continue
        if not nsum-asum-x-y:
            posstakeout.add((x,y))
res=[]
need=False
for x in posstakeout:
    arr=[x[0]]
    for y in a:
        b=y-arr[-1]
        if b<1:
            need=True
            break
        arr.append(b)
    if need:
        need=False
        continue
    if arr[-1]==x[1] and len(set(arr))==len(arr):
        res.append(arr)
minim=res.pop(0)
for x in res:
    for y in n:
        s=minim[y-1]-x[y-1]
        if s:
            if s>0:
                minim=x
            break
with open("photo.out","w") as fout:
    fout.write(" ".join(map(str,minim)))