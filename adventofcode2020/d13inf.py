# part 2 is not my work. Look further for more details. All code that is not my work ends in a #.
file=open("i13", "r")
inputs=file.readlines()
file.close()

ins=inputs.copy()
ins[0]=int(ins[0])
ins[1]=[int(x) for x in ins[1].split(',') if x!="x"]
base=min(ins[1]) # for part 2
mods=[]
for x in ins[1]:
    mods.append((x-ins[0]%x,x))
# part 1 answer 104
print(min(mods)[0]*min(mods)[1])

# part 2: I cheated by going online. My attempt below. Too slow to produce the answer, but probably produces the correct one.
# a feasible solution can be found at line 56 in better_sols.py.
ins=inputs[1].split(",")
wnum=[] # indices with numbers
for x in range(len(ins)):
    if 'x' not in ins[x]:
        ins[x]=int(ins[x])
        wnum.append(x)

eta=100000000000000
step=ins[wnum.pop(0)]
while True:
    if eta%step==0:
        break
    eta-=1
wlen=len(wnum)
while ([(eta+x)%ins[x] for x in wnum].count(0)-wlen):eta+=step
# part 2 answer 842186186521918 (I don't know if my code produces that)
print(eta)