with open("photo.in","r") as fin:
    n,a=[list(map(int,x.split())) for x in fin.readlines()]

n=range(1,n[0]+1)
nasum=(1+n[-1])*n[-1]-sum(a) # sumrange modification. Originally sumrange()*2 but I improved it
# try taking out one at a time per one at a time
need=False
need1=False
for x in n:
    rsum=nasum-x # revised sum
    for y in n:
        if y==x: continue
        if not rsum-y:
            arr = [x]
            for z in a:
                b = z - arr[-1]
                if b < 1:
                    need = True
                    break
                arr.append(b)
            if need:
                need = False
                continue
            if arr[-1] == y and len(set(arr)) == len(arr):
                need1=True
                break
    if need1:
        break
with open("photo.out","w") as fout:
    fout.write(" ".join(map(str,arr)))