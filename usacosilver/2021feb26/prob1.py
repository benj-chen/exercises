n=int(input())
ins=[]
two=(2,-2)
adj = [(x,y) for x in range(-1,2) for y in range(-1,2) if (x==0 or y==0) and (x or y)]
for q in range(n):
    ins.append(tuple(map(int,input().split())))
    change=[]
    for x in ins:
        ct=0
        for y in adj:

            if (x[0]+y[0],x[1]+y[1]) in ins:
                ct+=1
        if ct==3:
            change.append(x)
    # vert/hori and diff by 2, take 2 at a time
    change.sort()
    rmadd=int(len(change)==1)
    for x in range(0,len(change)-1):
        if change[x][0]-change[x+1][0] in two and change[x][1]-change[x+1][1] not in two:
            rmadd+=1
        elif change[x][0]-change[x+1][0] not in two and change[x][1]-change[x+1][1] in two:
            rmadd+=1
        else:
            rmadd+=2

    print(rmadd)