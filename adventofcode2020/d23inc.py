with open("i23","r") as fin:n=list(map(int,fin.readline()))

# use mod to maintain the place
mod= lambda x: x%(len(n))
# do a move 100x
ci=0
try:
    for y in range(10):
        nci=(list(map(mod,range(ci+1,ci+4))))
        nextc=[n[x] for x in nci]
        for x in list(range(n[ci]-1,min(n)-1,-1))+list(range(max(n),n[ci],-1)):
            if x not in nextc:
                break
        di=n.pop(n.index(x))
        # user insert method
        n.insert(ci+1,x)
        print(ci)
        ci=di
        print(n)
        print(ci)
except:
    print(y,"error")

    # do something to ci