"""
ID: benjche1
LANG: PYTHON3
TASK: gift1
"""
fin,fout=open('gift1.in','r'),open('gift1.out','w')
g=[x.strip() for x in fin.readlines()]
fin.close()
names={}
for x in range(1,int(g.pop(0))+1):
    names[g.pop(0)]=0
for x in range(len(g)):
    if g[x] not in names:
        g[x]=list(map(int,g[x].split()))
print(g)
print(names)
print(len(g))
for x in range(len(g)):
    if type(g[x])==list:
        try:
            g[x][0]-=g[x][0]%g[x][1]
            names[g[x-1]]-=g[x][0]
            z=g[x][0]//g[x][1]
            for y in g[x+1:x+g[x][1]+1]:
                names[y]+=z
        except:
            del g[x],g[x-1]

for x in names:
    fout.write('{} {}\n'.format(x,names[x]))