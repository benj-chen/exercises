with open('dec17input','r') as fin:
    INPUTS=[x[:-1] for x in fin.readlines()]

# point (0,0,0) in order z,y,x is the top left of the input

c={0:INPUTS[:]} # key:int is the z level, value:list of y strings that are x long is the orthographic image of active and inactive cubes
ADJ=[(dz, dy, dx) for dz in range(-1,2) for dy in range(-1, 2) for dx in range(-1, 2) if dx or dy or dz]
# run 6 rounds
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