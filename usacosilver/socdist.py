with open("socdist.in","r") as f:
    ins=[list(map(int,x.split())) for x in f.readlines()]
n,m=ins.pop(0)
ins.sort()
# get max d
d=0
for x in range(len(ins)-1):
    d=max(d,ins[x+1][0]-ins[x][1])
ranges=[ins[x+1][0]-ins[x][0]-1 for x in range(len(ins)-1)]+[ins[-1][1]-ins[-1][0]+1]
print(ranges)
for interval in range(d,0,-1):
    t=d-1
    for x in ranges:
        t-=x//interval
    # for x in range(len(ins)-1):
    #     # addon distance
    #     add=ins[x+1][0] -1
    #     t-=(add-ins[x][0])//interval
    # t-=(ins[x][1]-ins[x][0])//interval
    if t<=0:
        break
    # last one exception

with open('socdist.out','w') as g:
    g.write(str(interval))