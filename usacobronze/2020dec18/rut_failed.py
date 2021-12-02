n=int(input())
inputs=[]
for x in range(n):
    z=input().split()
    z[1:]=list(map(int,z[1:]))+list(map(int,z[1:]))+[False]+[x]
    inputs.append(z)
nfacing=[x for x in inputs if x[0]=="N"]
efacing=[x for x in inputs if x[0]=="E"]
nfacing=[y[1:] for y in sorted([[sum(x[1:3])]+x for x in nfacing])]
efacing=[y[1:] for y in sorted([[sum(x[1:3])]+x for x in efacing])]
nlen,elen=map(len,[nfacing,efacing])
path=[]
for x in range(min(nlen,elen)):
    path.append(efacing[x][-1])
    path.append(nfacing[x][-1])
if nlen>elen:
    path.extend(nfacing[elen:])
if nlen<elen:
    path.extend(nfacing[nlen:])
eaten=set() # contain coordinates
res=[]
for x in inputs:
    res.append([])
# go in n**2 style, choose the lowest
for a in path:
    x=inputs[a]
    mindist=100000000000
    for y in inputs:
        if x==y or x[0]==y[0]: continue

        if x[0]=="N": # look at the ydelta
            if y[4]-x[2]>0:
                print('if if')
                mindist=min(mindist,y[4]-x[2])

        else:
            if x[3]-z[3]<0:
                print('else if')
                mindist = min(abs(mindist), x[3]-z[1])
    print()
    res[a]=(mindist)
print(res)


# simulate now
# so close... probably have to sort specially

for a in path: # change the order depending on the
    x=inputs[a]
    marked=False
    result=[]
    if x[0]=="N": # is good
        for z in [y[1:] for y in inputs if y[0]=='E']:
            xdelta=x[1]-z[0]
            ydelta=z[1]-x[2]
            if xdelta<0 or ydelta<0:
                continue

            if xdelta<ydelta: # current gets to it firs
                x[3]+=xdelta
                x[4]+=ydelta
                result.append(ydelta)
                z[4]=True
                marked=True
            else: # other gets to it, stop
                x[5]=True
                x[3]+=xdelta
                x[4]+=ydelta
    else: # is not good, direction is E
        for z in [y[1:] for y in inputs if y[0]=='E' and y!=x]: # change the list comprehension if
            xdelta=x[1]-z[0]
            ydelta=z[1]-x[2]
            print(z[2])
            print(x[0])
            if (z[2]<x[1] and z[3]<x[2]):
                continue
            print(z)
            print(xdelta)
            print(ydelta)
            print()
            if xdelta>ydelta: # current gets to it first # this never runs
                x[5]=True
                x[3]+=xdelta
                x[4]+=ydelta
            else: # other gets to it, stop
                x[3]+=xdelta
                x[4]+=ydelta
                result.append(ydelta)
                z[4]=True
                marked=True
    if not marked:
        res[a]=['Infinity']
    else:
        res[a]=[min(map(abs,result))]
for x in res:
    print(*x)

"""


n=int(input())
inputs=[]
for x in range(n):
    inputs.append(input().split())
    inputs[-1].insert(0,sum(map(int,inputs[-1][1:])))
INPUTS=[x[0] for x in inputs]
inputs.sort()

inputs=[[x[1]]+list(map(int,x[2:]))+[False]+x[0] for x in inputs]
print(inputs)
eaten=set() # contain coordinates
res=[]
for x in inputs:
    marked=False
    result=[]
    if x[0]=="N": # is good
        for z in [y[1:] for y in inputs if y[0]=='E']:
            xdelta=x[1]-z[0]
            ydelta=z[1]-x[2]
            if xdelta<0 or ydelta<0:
                continue

            if xdelta<ydelta: # current gets to it first
                z[2]=True
                result.append(ydelta)
                marked=True
            else:
                x[3]=True
    else: # is not good
        print('else initiated')
        print(x)
        print()
        for z in [y[1:] for y in inputs if y[0] == 'N' and not y[3]]:
            print(z)
            xdelta=x[1]-z[0]
            ydelta=z[1]-x[2]
            print(xdelta)
            print(ydelta)
            print()
            if xdelta>0 or ydelta>0:
                continue

            if xdelta < ydelta:  # current gets to it first STOP THE OTHER ONE
                result.append(abs(xdelta))
                marked=True
                z[2]=True
            else:
                x[3]=True
    if not marked:
        result.append("Infinity")
    res.append(min(result))
# for x in inputs:
#     marked=False
#     result=[]
#     if x[0]=="N": # is good
#         print('if initiated')
#         for z in [y[1:] for y in inputs if y[0]=='E']:
#             xdelta=x[1]-z[0]
#             ydelta=z[1]-x[2]
#             if xdelta<0 or ydelta<0:
#                 continue
#
#             if xdelta<ydelta: # current gets to it first
#                 x[3]+=xdelta
#                 x[4]+=ydelta
#                 result.append(ydelta)
#                 marked=True
#             else: # other gets to it, stop
#                 x[3]+=xdelta-1
#                 x[4]+=ydelta-1
#     else: # is not good, direction is E
#         print('else initiated')
#         for z in [y[1:] for y in inputs if y[0] == 'N' and y[4]>=x[2] and y[3]<=x[1]]: # change the list comprehension if
#             xdelta=x[1]-z[0]
#             ydelta=z[1]-x[2]
#             if xdelta>0 or ydelta>0:
#                 continue
#
#             if xdelta < ydelta:  # current gets to it first
#                 x[3]+=xdelta
#                 x[4]+=ydelta
#                 result.append(xdelta)
#                 marked=True
#             else: # other gets to it, stop
#                 x[3]+=xdelta-1
#                 x[4]+=ydelta-1
#     if not marked:
#         result.append("Infinity")
#     res.append(result)
#     print('end of iter')
print(res)
"""