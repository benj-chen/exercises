# setup for input


n,k=map(int,input().split())
ins=[tuple(map(lambda x: int(x)-1,input().split())) for x in range(k)]

# dict holds the values that start goes to
nn=range(n)
goto=[]
for x in nn: goto.append(set())

lrn=list(nn)
for x in ins:
    lrn[x[0]],lrn[x[1]]=lrn[x[1]],lrn[x[0]]
    
    goto[lrn[x[0]]].add(x[0])
    goto[lrn[x[1]]].add(x[1])
# last is lrn
def getgroup(x,init):
    if x==init: return (x,)
    return (x,)+getgroup(lrn[x],init)
res={}

def union(setgroup):
    res=set()
    for i in setgroup:
        res|=i
    return res

for x in nn:
    gr = getgroup(lrn[x],x)
    if gr not in res: res[gr] = max(1,len(union([goto[y] for y in gr])))
    print(res[gr])

# goto=list(map(set,goto))
# print("lrn:",lrn)
# print("goto:",goto)
# # last is lrn
# nums=[]
# for x in nn: nums.append(set())
# res=[]
# for x in nn: res.append([])
# def recurse(targ,st):
#     if st==targ: return nums[targ]
    
#     if not nums[targ]:
#         nums[targ]=goto[targ] | recurse(lrn[targ],st)
#     # else check?
#     else:
#         nums[targ]=goto[targ] | recurse(lrn[targ],st)
#     return nums[targ]
# # sort into groups because one of them will share the rest with the group!
# # get the groups



# for x in nn:
#     nums[x]=goto[x] | recurse(lrn[x],x)
#     print(nums)
#     print(len(nums[x]))

# goto=tuple(map(lambda x: list(set(x)),goto))
# # last is lrn
# #
# def recurse(targ,st,visited):
#     if st==targ: return
#     else:
#         for x in goto[targ]: visited[x]=True
#         recurse(lrn[targ],st,visited)

# for x in nn:
#     s=[False]*n
#     for y in goto[x]:
#         s[y]=True
#     recurse(lrn[x],x,s)
#     print(max(1,sum(s)))



# n,k=map(int,input().split())
# ins=[tuple(map(lambda x: int(x)-1,input().split())) for x in range(k)]
# # sim
# arr=list(range(n))
# goto={x: {x} for x in arr}
# # make first swap
# def hasRecSeq(ls): # recurring sequence
#     if len(ls)>1:
#         return False
#     if len(ls)%2:
#         return

# def track(num): # i is the list of swaps
#     reached=[num]
#     # reach is num[-1]
#     # while True:
#     isin=False
#     for x in ins:
#         if num in x:
#             isin=True
#             break
#     if not isin:
#         return [[True]]
#     total=[]
#     while True:
#         for x in ins:
#             # print(reached)
#             if reached[-1] in x:
#                 # if (x[0]==reached[-1] and x[1] in reached) or (x[1]==reached[-1] and x[0] in reached):
#                 # if x[0] in reached and x[1] in reached:
#                 #     print(x)
#                 #     return reached
#                 reached.append(x[0] if x[0]!=reached[-1] else x[1])
#         if reached in total:
#             return total
#         total.append(reached)
# # print(len(set(*track(3))))
# # print("\n\n\n")
# # for y in arr:
# #     print(len(set(*track(y))))
# minute=0
# base=list(range(n))
# while True:
#     # print(arr)
#     goto[arr[ins[minute][0]]].add(ins[minute][1])
#     goto[arr[ins[minute][1]]].add(ins[minute][0])
#     arr[ins[minute][0]],arr[ins[minute][1]]=arr[ins[minute][1]],arr[ins[minute][0]]
#     if arr==base:
#         break
#     # if minute+1==k:
#         # print("e")
#     minute=(minute+1)%k
# for x in goto:
#     print(len(goto[x]))
# # 52:00.00: pass 5 test cases. In other words, not scalable, since "Test cases 1-5 satisfy N≤100,K≤200."

