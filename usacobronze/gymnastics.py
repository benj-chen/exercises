with open("gymnastics.in","r") as fin:
    ins=fin.readlines()
k,n=map(int,ins.pop(0).split())
rank={x:() for x in range(1,n+1)}

for x in [list(map(int,i.split())) for i in ins]:
    for y in range(len(x)):
        rank[x[y]]+=(y,)
pair=0
for x in rank:
    i=rank[x]
    for y in rank:
        # only compare unique pairs
        if x>=y:
            continue
        j=rank[y]
        comp=[a>b for a,b in list((i[c],j[c]) for c in range(k))]
        if (True in comp and False not in comp) or (False in comp and True not in comp):
            pair+=1
with open("gymnastics.out","w") as fout:
    fout.write(str(pair))