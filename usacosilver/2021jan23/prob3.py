n=int(input())
pts=[list(map(int,input().split())) for x in range(n)]

print(pts)
cow=[]
for x in pts:
    cow.append([y>1 for y in x])
print(cow)
def problem(cows):
    for x in range(n-1):
        # consider x and x+1
        for y in range(n-1):
            s=cows[x][y]+cows[x+1][y]+cows[x][y+1]+cows[x+1][y+1]
            if s!=2:
                return x,y,s>2
    return False
prob=problem(cow)
while prob:
    pass
    if prob[2]: # too many, try removing one at a time... it's guaranteed that you'll get a swappable cow by the second try
        for x in range(1,5):
            # there could be two that need to be remooved
            temp=cow[prob[0][x%2]][prob[1][x>2]]
            cow[prob[0][x%2]][prob[1][x>2]]=False
            probl=problem(cow)
            if not probl:
                tobreak=True
                break
            if probl[:2]!=prob[:2]:
                break
            if probl==prob:
                # it was already False or it needs to go again.
                pass
            cow[prob[0][x % 2]][prob[1][x > 2]] = temp
        assert prob!=probl
    if tobreak:
        break
            # mod 2, over 1

    prob = problem(cow)
b=0 # beauty points
for x in range(len(cow)):
    for y in range(x):
        if cow[x][y]:
            b+=pts[x][y]
print(b)