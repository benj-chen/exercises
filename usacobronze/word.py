with open("word.in","r") as fin:
    [n,k],essay=[x.split() for x in fin.readlines()]
res=[essay.pop(0)]
k=int(k)
for x in essay:
    if len(x)+len(res[-1])>k+res[-1].count(" "):
        res+=[x]
    else:
        res[-1]+=" "+x
with open("word.out","w") as fout:
    fout.write('\n'.join(res))