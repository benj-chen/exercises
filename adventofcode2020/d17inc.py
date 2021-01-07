with open('i17', 'r') as fin:
    INPUTS=[x[:-1] for x in fin.readlines()]

# point (0,0,0) in order z,y,x is the top left of the input

c={0:INPUTS[:]} # key:int is the z level, value:list of y strings that are x long is the orthographic image of active and inactive cubes
ADJ=[(dz, dy, dx) for dz in range(-1,2) for dy in range(-1, 2) for dx in range(-1, 2) if dx or dy or dz]
print(c)
# run 6 rounds
def expz(d):
    a=["."*len(d[0][0])]*len(d[0])
    d[min(d)-1],d[max(d)+1]=(a[:],a[:])
def expy(d):
    a="."*len(d[0][0])
    for i in d:
        d[i].append(a)
        d[i].insert(0,a)
def expx(d):
    for i in d:
        for x in range(len(a:=d[i])):
            a[x]="."+a[x]+"."

print(c)
for round in range(7):

    print()
    change=[]

    print("After",round,"cycle:")
    for x in c:
        print("z =",x)
        for y in (c[x]):
            print(y)
    for i in c:
        for j in range(len(c[i])):
            for k in range(len(c[i][j])):
                active=c[i][j][k]=="#"
                acount=0
                for a in ADJ:
                    if 0<=(i1:=i+a[0])<=max(c) and -1<(j1:=j+a[1])<len(c[i]) and -1<(k1:=k+a[2])<len(c[i][j]):
                        print(a)
                        acount+=int(c[i1][j1][k1]=="#")
                if active and not(1<acount<4):change.append(((i,j,k),"."))
                if not active and acount==3:change.append(((i,j,k),"#"))
                print()
    for x,y in change:
        # c[x[0][0]][x[0][1]] = c[x[0][0]][x[0][1][:x[0][2]]+x[1]+ c[x[0][0] ][ x[0][1] ][ x[0][2+1:]]

        c[x[0]][x[1]]=c[x[0]][x[1]][:x[2]]+y+c[x[0]][x[1]][x[2]+1:]
    expx(c)
    expy(c)
    expz(c)
count=0

for x in c.values():
    for y in x:
        count+=y.count("#")
print(count)
"""
l,w=len(INPUTS[0]),len(INPUTS)
for round in range(1):
    print(c)
    mc=min(c.keys())
    c[mc-1]=[]
    maxc=max(c.keys())+1
    c[maxc]=[]
    for v in range(w):
        c[mc-1]+=['.'*l]
        c[maxc]+=['.'*l]
    # gotta add another y layer to the end and beginning of each z layer, and another x layer.
    atoi=None # active to inactive

    for z in c: # z is the actual z coordinate
        cz=c[z]
        for y in range(len(cz)): # y is actually y
            czy=cz[y]
            for x in range(len(czy)): # x is actually x
                active=c[z][y][x]=="#"
                a=0 # active count
                # get active cubes around point (z,y,x)
                for pt in ADJ:
                    if z+pt[0] not in c or \
                        y+pt[1]<0 or y+pt[1]>=len(cz) or \
                        x+pt[2]<0 or x+pt[2]>=len(czy):
                        continue
                    if c[z+pt[0]][y+pt[1]][x+pt[2]]=="#": # there could be an undeclared z layer, y column, or x row.
                    # could go for a try, except thing I guess, or something smarter?
                        a+=1
                if active:
                    if a not in {2,3}: # becomes inactive
                        c[z][y]=c[z][y][:x]+'.'+c[z][y][x+1:]
                else:
                    if a==3:
                        c[z][y]=c[z][y][:x]+'#'+c[z][y][x+1:]


print(c)
# count the number of active cubes
active=0
for x in c.values():
    for y in x:
        active+=y.count("#")
print(active)
c={0:INPUTS[:]} # key:int is the z level, value:list of y strings that are x long is the orthographic image of active and inactive cubes
print(c)
for round in range(1):

    c[mc-1]=[]
    maxc=max(c.keys())+1
    c[maxc]=[]
    for v in range(w):
        c[mc-1]+=['.'*l]
        c[maxc]+=['.'*l]
    copy=dict()
    for d in c:
        copy[d]=c[d].copy()
    assert copy==c
    assert not(copy is c)
    mc=min(c.keys())
    for z in c: # z is the actual z coordinate
        cz=copy[z]
        for y in range(len(cz)): # y is actually y
            czy=cz[y]
            for x in range(len(czy)): # x is actually x
                active=copy[z][y][x]=="#"
                a=0 # active count
                # get active cubes around point (z,y,x)
                for pt in ADJ:
                    if z+pt[0] not in c:
                        continue
                    if y+pt[1]<mc-1 or y+pt[1]>=len(cz):
                        continue

                    if x+pt[2]<0 or x+pt[2]>=len(czy):
                        continue
                    if copy[z+pt[0]][y+pt[1]][x+pt[2]]=="#":
                        a+=1
                if active:
                    if a not in {2,3}: # becomes inactive
                        c[z][y]=c[z][y][:x]+'.'+c[z][y][x+1:]
                else:
                    if a==3:
                        c[z][y]=c[z][y][:x]+'#'+c[z][y][x+1:]
    print(copy)
    print(c)
# count the number of active cubes
active=0
for x in c.values():
    for y in x:
        active+=y.count("#")
print(active)
"""