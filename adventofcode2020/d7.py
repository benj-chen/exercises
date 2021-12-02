file=open("i7", 'r')
ins=file.readlines()
file.close()

values=dict()
for x in ins:
    temp=x.split("contain")
    values[temp[0].strip()[:-5]]=[' '.join(x.strip().split(' ')[1:-1]) for x in temp[1][:-2].strip().split(',')]

global res
res=set()
def addUniqueParents(d: dict,target: str="shiny gold")-> None:
    # if the target has no parent, end recursion and return
    targetInD=False
    for i in d.values():
        if target in i:
            targetInD=True
    if not targetInD:
        return
    for i in d.keys():
        if target in d[i]:
            res.add(i)
            addUniqueParents(d,i)
addUniqueParents(values)
# part 1 answer 355
print(len(res))
global count
count=0

values=dict()
for x in ins:
    sep=x.split("contain") #separate the line into the container and the containees
    noBag=[x for x in sep[1].strip().split(' ') if "bag" not in x] # among the containees, separate the bags with the keyword "bag"
    temp=[]
    for x in range(len(noBag)): #draw out the number of bags: for example, two "red" bags would show as "red", "red"
        if len(noBag[x])==1:
            temp.append(int(noBag[x])*(noBag[x+1]+' '+noBag[x+2]+' '))

    temp1=[]
    shouldsep=False
    for x in ''.join(temp).split(): #put the bag names into their own list
        if not shouldsep:
            temp1.append([])
        temp1[-1].append(x)
        shouldsep=not shouldsep

    for x in range(len(temp1)):temp1[x]=' '.join(temp1[x]) #rejoin the bag name into one string

    values[sep[0].strip()[:-5]]=temp1
def getNumBags(d: dict, target: str) -> None:
    global count
    if d[target]==['other']:
        return
    for x in d[target]:
        count+=1
        getNumBags(d,x)
getNumBags(values,"shiny gold")
# part 2 answer 5312
print(count)