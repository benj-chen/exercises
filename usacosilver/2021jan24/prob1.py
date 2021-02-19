n,k=map(int,input().split())
ins=[tuple(map(lambda x: int(x)-1,input().split())) for x in range(k)]
# sim
arr=list(range(n))
goto={x: {x} for x in arr}
# make first swap
def hasRecSeq(ls): # recurring sequence
    if len(ls)>1:
        return False
    if len(ls)%2:
        return

def track(num): # i is the list of swaps
    reached=[num]
    # reach is num[-1]
    # while True:
    isin=False
    for x in ins:
        if num in x:
            isin=True
            break
    if not isin:
        return [[True]]
    total=[]
    while True:
        for x in ins:
            # print(reached)
            if reached[-1] in x:
                # if (x[0]==reached[-1] and x[1] in reached) or (x[1]==reached[-1] and x[0] in reached):
                # if x[0] in reached and x[1] in reached:
                #     print(x)
                #     return reached
                reached.append(x[0] if x[0]!=reached[-1] else x[1])
        if reached in total:
            return total
        total.append(reached)
# print(len(set(*track(3))))
# print("\n\n\n")
# for y in arr:
#     print(len(set(*track(y))))
minute=0
base=list(range(n))
while True:
    # print(arr)
    goto[arr[ins[minute][0]]].add(ins[minute][1])
    goto[arr[ins[minute][1]]].add(ins[minute][0])
    arr[ins[minute][0]],arr[ins[minute][1]]=arr[ins[minute][1]],arr[ins[minute][0]]
    if arr==base:
        break
    # if minute+1==k:
        # print("e")
    minute=(minute+1)%k
for x in goto:
    print(len(goto[x]))
# 52:00.00: pass 5 test cases. In other words, not scalable, since "Test cases 1-5 satisfy N≤100,K≤200."

