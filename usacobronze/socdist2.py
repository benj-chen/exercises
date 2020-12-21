rl=lambda x: range(len(x))
def get_input(arg):
    f=open("socdist2_bronze_open20/"+arg,'r')
    ins=f.readlines()
    f.close()
    return ins
inp=get_input('2.in')
print(inp)
ins=[int(inp[0])]
for x in inp[1:]:
    ins.append(tuple(map(int,x.split())))
ins=[ins[0]]+sorted(ins[1:])
print(ins)

inp=[ins[0],[x[0] for x in ins[1:]],[x[1] for x in ins[1:]]]

ins=inp
print(ins)
# 0 is in ins
# assert 0 in ins[2]
# assert 0 in [x[1] for x in ins[1:]]

# get lowest r
lowestR=max(ins[1])
startindex=ins[2].index(0)
for x in range(ins[2].count(0)):

    targ_index=ins[2][startindex:].index(0)+startindex
    prevRExists=False
    aftRExists=False
    if targ_index>0: # isn't first thing
        prevR=ins[1][targ_index]-ins[1][targ_index-1]-1
        prevRExists=True
    if targ_index<len(ins[2]): # isn't last thing
        aftR=ins[1][targ_index+1]-ins[1][targ_index]
        aftRExists=True
    if prevRExists and aftRExists:
        r=min(prevR,aftR)
    elif prevRExists:
        r=prevR
    else:
        r = aftR
    try:
        print('prevR:',prevR)
        print('aftR:',aftR)
    except:
        print('aftR:',aftR)

    print(r)
    lowestR=min(lowestR,r)
    startindex=targ_index
print(lowestR)
# lowestR is inclusive, so if a space looks like 1__0 where 1 is an infected cow, 0 isn't, and _ is empty, lowestR=2
# however in 1_0: lowestR=1. lowestR is the number of spaces around a cow to which cows in the radius get infected
initcows=0

# separate by r
r=[[]]
for x in range(len(ins[2])-1):
    try:
        if not ins[2][x]:
            ins[2].pop(x)
            ins[1].pop(x)
    except:
        break
print(ins)

for x in range(len(ins[1])):



    if ins[1][x]-ins[1][x-1]>lowestR:
        r.append([ins[1][x]])
    else:
        r[-1].append(ins[1][x])
print(r)
print(len(r))
# before handling cases after lowestR
if ins[2][:lowestR].count(1):
    initcows+=1

for x in range(lowestR,len(ins[1])-2):
    item=ins[1][x]
    previtem=ins[1][x-1]
    nextitem=ins[1][x+1]
    if not(ins[1][x] and ins[1][x-1] and ins[1][x+1]):
        continue

    # if it's completely isolated
    if item-previtem>2 and nextitem-item>2:
        initcows+=1
        continue



    if item-previtem<=lowestR:
        #one of them was unnecessary?
        pass