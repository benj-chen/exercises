## restarting because yes
## tree, direct attention to test cases 1-4
## binary tree for test cases 5-7 (except for farm 1)

n = int(input())
paths=[tuple(map(lambda x: int(x)-1,input().split())) for x in range(n-1)]
# log2 = lambda n: (n-1).bit_length() # ceil log2 n

# print(log2(n)+n-1)
#^ test cases 1-4
ct=n-1 # minimum count, 
go=[]
for x in range(n):
    go.append([])
for x in paths:
    go[x[0]].append(x[1])
    go[x[1]].append(x[0])
print(go)
maxlenind=(-1,-1)
for x in go:
    l=len(x)
    if l>maxlenind[0]:
        maxlenind=[l,x]

## make some map of something
# conn = []
# n=int(input())
# paths=[tuple(map(int,input().split())) for x in range(n-1)]
# f={x:[] for x in range(1,n+1)}# farm paths
# for x in paths:
#     f[x[0]].append(x[1])
#     f[x[1]].append(x[0])
# from math import log2
# supers=(0,-1)
# for x in f:
#     supers=max(supers,(len(f[x]),x))
# # search tree?
# def round(x):
#     return int(x)+(int(x)!=x)
# ln=round(log2(supers[0]))
# # then, find the distance from a key to the superspreader location
# # get the length it takes for a start to go to a target
# # print(f)
# target=supers[1]
# # oh yea, dp
# global targdict
# targdict={x:1 for x in f[target]}
# targdict[target]=0
# targdict.update({x:100001 for x in range(1,n+1) if x not in targdict})
# print(targdict)
# def rec(st,targ): # void
#     for x in f[st]:
#         if targdict[x]==100001:
#             rec(x,targ)
#         targdict[st]=min(targdict[st],targdict[x] + 1)


# for x in f:
#     if x not in targdict:
#         rec(x,target)
# print(targdict)
# # def rec(st,targ,step=0): # return void/None
# #     if st in targdict:
# #         return targdict[st]
# #     if len(f[st])==1 and f[st][0]!=targ:
# #         return False
# #     if st==targ:
# #         targdict[st]=step
# #         return True,step
# #     step+=1
# #     for x in f[st]:
# #         a=rec(x,targ,step)
# #         if a:
# #             targdict[a[1]]=step
# #             return a
# #     return False
# # ln+=rec(supers[1],1)[1]
# print(ln+sum(targdict.values())+targdict[1])
# # timestamp 56:01.83 min:sec.ms