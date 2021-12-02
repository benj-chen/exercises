with open("lineup.in","r") as fin:
    ins=fin.readlines()
n=int(ins.pop(0))
# first assume that the input is in order
# res=["*", "Bessie","*", "Buttercup", "*", "Belinda", "*", "Beatrice", "*", "Bella", "*", "Blue", "*", "Betsy", "*","Sue","*"]
# do some sorting to the ins to have the names appear in order
a=[]
for x in ins:
    y=x.split()
    a.extend((y[0],y[-1]))
nnum={"Bessie":0,"Buttercup":1,"Belinda":2,"Beatrice":3,"Bella":4,"Blue":5,"Betsy":6,"Sue":7}
ins=[[nnum[x.split()[0]],nnum[x.split()[-1]]] for x in ins]
# ord=[ins.pop(0)]
# for x in ins:
#
#     if x[0]==ord[-1][-1]:
#         ord[-1].append(x[1])
#     elif x[1]==ord[-1][-1]:
#         ord[-1].append(x[0])
#     else:
#         ord.append(x)
# print(ord)
# dict recursion again lmao
print(ins)
nextto={x:[] for x in range(8)}
for x in ins:
    nextto[x[0]].append(x[1])
    nextto[x[1]].append(x[0])
print(nextto)
# every value either has 0,1, or 2 values
# each key can also only appear at most twice in any other value
freemove=[]
groups=[[]]
def getseq(cow):
    # init cow must be the start of the seq
    if not nextto[cow]:
        return [cow]
    if len(nextto[cow])==1:
        # it's on the edge
        return [cow]+getseq(nextto[cow][0])
    for x in nextto[cow]:
        if x==cow:
            continue
        return [cow]+getseq(x)
    # must be surrounded then

print(groups)
try:
    for x in nextto:
        if not nextto[x]:
            freemove.append(x)
            continue
        if len(nextto[x])==1:
            # start/end of a sequences
            groups.append(getseq(x))
except: pass
# ins.pop()
# res=[a.pop(),a.pop()]
# print(res)
# look at index 1 and 2, then 3 and 4, etc. If the two indexes are the same, then add that to the group that already
# exists, otherwise make a new group.
groups=[[a[0]]]
for x in range(1,len(a)-1,2):
    if a[x]==a[x+1]:
        groups[-1].extend((a[x],a[x+2]))
    else:
        groups.append([a[x]])
# res=[[]]
# for x in range(2,len(a)-1,2):
#     if a[x]==a[x-1]:
#         res[-1].extend((a[x-2],a[x+1]))
#     else:
#         res.append(a[x:x+2])
# print(res)
# print(a)
# group=[list(ins.pop())]
# print(group)
# for x in ins:
#     found=False
#     for groups in group:
#         if x[0] in groups:
#             found=True
#             if groups.index(x[0])==0:
#                 groups.insert(0,x[1])
#             else:
#                 groups.append(x[1])
#             ins.remove(x)
#
#         if x[1] in groups:
#             found=True
#             if groups.index(x[1])==0:
#                 groups.insert(0,x[0])
#             else:
#                 groups.append(x[0])
#             ins.remove(x)
#     if not found:
#         group.append(list(x))
#         ins.remove(x)
#     print(x)
# print(group)
# consider=a.pop()
# for x in range(len(a)):
#     print(x)

# for x in range(len(a)):
#     if a.count(a[x])>1:
#         if x%2: # x is in an odd index


with open("lineup.out","w") as fout:
    pass