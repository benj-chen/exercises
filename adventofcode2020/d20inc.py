# contains use of the "walrus operator" which requires Python 3.8 or better - see README
with open('i20','r') as fin:
    inputs=fin.readlines()+['\n']
# assume each tile has the same length and width.
# assume the final picture is a square, with the same length and width of tiles.
borders= {} # tile ID: four strings representing the border in the order TOP, LEFT, RIGHT, BOTTOM
# if anything is in borders[-1], something went wrong
tileid=-1
allborders=[]
# get borders per tile
for x in range(len(inputs)):
    if ":" in (toConsider:=inputs[x]):
        tileid=int(toConsider[5:-2])
        borders[tileid]=[inputs[x+1][:-1],'','']
        y=x+1
        while (z:=inputs[y])!="\n":
            borders[tileid][1]+=z[0]
            borders[tileid][2]+=z[-2]
            y+=1
        borders[tileid].append(inputs[y-1][:-1])
        allborders.extend(borders[tileid])
print(borders)
lw=len(borders)
workingb=[]
for x in allborders:
    if (allborders.count(x)+ allborders.count(''.join(reversed(x))))==1:
        workingb.append(x)
print(workingb)
corners=[]
# has to have two working borders in it to count
edges=[]
# has to have exactly one working border in it to count
# if something has three working borders (which is impossible assuming the assumptions made in the beginning) then that would go to edges.
for x in borders:
    works=False
    for y in workingb:
        if y in borders[x]: # if a working border is in there...
            if works:
                corners.append([x,borders[x].index(y),])
                break
            works=not works
    if works:
        edges.append(x)


print(edges)
res=1
c_orient=[] # [corner, (flip) True or False] in the order UL,UR,DL,DR
def flip(expr:list)->list:
    return [''.join(reversed(x)) for x in expr]
for x in corners:
    res*=x[0]
# part 1 answer 15003787688423
print(res)
# construct the actual image

image=[] # its length is however many

for x in corners:
    print(x)
    numvisited=0
    for y in borders[x]:
        if y in workingb:
            print(borders[x].index(y))
            numvisited+=1
    if numvisited<2:
        for y in borders[x]:
            if ''.join(reversed(y)) in workingb:
                print(borders[x].index(y))
                numvisited += 1


mon="""                  # 
#    ##    ##    ###
 #  #  #  #  #  #   """.split("\n")
print(mon)

# a full image has 8 possible orientations - right 0 deg, flipped; r0, unflipped; r90, flipped; r90, unflipped and so on.


for x in borders:
    for y in workingb:
        if y in (z:=borders[x]): # if a working border is in there...
            edges.append([x,z.index(y)])