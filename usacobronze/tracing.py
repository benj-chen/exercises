with open('tracing.in','r') as fin:
    inputs=fin.readlines()
n=int(inputs[0].split()[0]) # number of cows
numints=int(inputs[0].split()[1]) # number of interactions
health=inputs[1]
HEALTH=health[:]
ints=[y[1:] for y in sorted([tuple(map(int,x.split())) for x in inputs[2:]])] # (timestamp, shaker, shakee)
print(ints)
template=('0'*n)
patient=[]
# among the infected cows, iterate through each and see if it works I guess
for x in range(n):
    if health[x]=='0': continue
    curhealth=template[:x-1]+'1'+template[x+1:]
    if x==0:
        curhealth='1'+template[1:]
    for shaker,shakee in ints:
        if curhealth[shaker-1]=="1": # if shaker is infected
            print(shaker,'infected',shakee)
            print(curhealth)
            curhealth=curhealth[:shakee]+'1'+curhealth[shakee+1:]
            print(curhealth)
    if curhealth==health:
        patient.append(x+1)
print(patient)
with open('tracing.out','w') as fout:
    pass