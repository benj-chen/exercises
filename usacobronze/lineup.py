with open("lineup.in","r") as fin:
    ins=fin.readlines()
n=int(ins.pop(0))
# first assume that the input is in order
# res=["*", "Bessie","*", "Buttercup", "*", "Belinda", "*", "Beatrice", "*", "Bella", "*", "Blue", "*", "Betsy", "*","Sue","*"]
a=[]
for x in ins:
    y=x.split()
    a.extend((y[0],y[-1]))
ins=[(x.split()[0],x.split()[-1]) for x in ins]
#
# ins.pop()
# res=[a.pop(),a.pop()]
# print(res)
print(ins)
print(a)
groups=[[]]
res=[[]]
for x in range(2,len(a)-1,2):
    if a[x]==a[x-1]:
        res[-1].extend((a[x-2],a[x+1]))
    else:
        res.append(a[x:x+2])
print(res)
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