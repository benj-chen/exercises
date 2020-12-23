with open('dec16input','r') as fin: INPUTS=[x[:-1] for x in fin.readlines()]
params=[]
paramsfin=False
myticketfin=False
tickets=[]
for x in INPUTS:
    if not x: paramsfin=True
    elif x=='your ticket:': myticketfin=True
    elif myticketfin:
        myticket=tuple(map(int,x.split(',')))
        myticketfin=False
    elif not paramsfin: params.append(x.split(': '))
    elif x=="nearby tickets:": continue
    else: tickets.append(tuple(map(int,x.split(','))))
del myticketfin,paramsfin

for x in params:
    x[1]=x[1].split(" or ")
    for y in range(len(x[1])):
        x[1][y]=tuple(map(int, x[1][y].split('-')))

stinkyvals=[]
for a in tickets:
    for b in a:
        isIn=False
        for c in [d[1] for d in params]:
            for e in c:
                if b>=e[0] and b<=e[1]:
                    isIn=True
                    break
        if not isIn:stinkyvals.append(b)
# part 1 answer 21978
print(sum(stinkyvals))

worktickets=[] # working tickets
for a in tickets:
    isin=True
    for b in a:
        isIn=False
        for c in [d[1] for d in params]:
            for e in c:
                if b>=e[0] and b<=e[1]:
                    isIn=True
                    break
        isin=isin and isIn
    if isin:worktickets.append(a)
p={x:y for x,y in params}

candidates=[]
assert worktickets
for x in range(len(myticket)):
    candidates.append(list(p.keys()))

winners=[]

for spot in range(len(candidates)):
    winners.append([])
    for candidate in candidates[spot]:
        reqs=p[candidate]
        isgood=True
        for ticket in [index[spot] for index in worktickets]:
            isGood=False
            for req in reqs:
                if ticket>=req[0] and ticket<=req[1]:
                    isGood=True
            isgood=isgood and isGood
        if isgood:
            winners[spot].append(candidate)

while sum(map(len,winners))!=len(winners):
    for winner in range(len(winners)):
        x=winners[winner]
        if len(x)==1:
            for y in winners:
                try:
                    if y!= x:
                        y.remove(x[0])
                except: pass
res={str(winners[x]):myticket[x] for x in range(len(winners))}
ans=1
for x in res:
    if 'departure' in x:
        ans*=(res[x])
# part 2 answer 1053686852011
print(ans)