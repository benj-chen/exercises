file=open("i5", "r")
inputs=[x[:-1] for x in file.readlines()]
file.close()
best=0
part2=[]
for line in inputs:
    llim = 0
    ulim = 127
    for char in line[:-3]:
        if char=="F":
            ulim-=((ulim-llim)//2+(ulim-llim)%2)
        else:
            llim+=((ulim-llim)//2+(ulim-llim)%2)
    if line[-3]=="F": row=ulim
    else: row=llim
    llim1=0
    rlim=7
    for char in line[-3:]:
        if char=="L":
            rlim-=(rlim-llim1)//2+(rlim-llim1)%2
        else:
            llim1+=(rlim-llim1)//2+(rlim-llim1)%2
    if line[-1]=="L": col=llim1
    else: col=rlim
    score=row*8+col
    part2.append(score)
    best=max(best,score)
# part 1 answer 896
print(best)

part2.sort()
for x in range(part2[0],part2[-1]):
    if x-1 in part2 and x+1 in part2 and x not in part2:
        break
# part 2 answer 659
print(x)