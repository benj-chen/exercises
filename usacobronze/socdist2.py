with open("socdist2.in","r") as fin:
    ins=[tuple(map(int,x.split())) for x in fin.readlines()[1:]] # ignore n: never used
ins.sort()
# find the lowest R, as described by the problem.
lr=ins[-1][0] # it can't be more than the maximum distance from the beginning
for x in range(len(ins)-1):
    # -1 is to allow to consider the last one without error
    if (ins[x][1] and not ins[x+1][1]) or (ins[x+1][1] and not ins[x][1]):
        # exactly 1 cow is infected
        lr = min(lr, ins[x+1][0] - ins[x][0])
icow=1 # initial cow count: +1 is for the ending chain
# weeding out all of the 0's, since they're not really needed anymore
ins=[x[0] for x in ins if x[1]]

for x in range(len(ins)-1):
    icow+=ins[x+1]>=ins[x]+lr # turns out you can add ints and booleans together, originally this was a function
with open("socdist2.out","w") as fout:
    fout.write(str(icow))
# aforementioned function:
# def socdist(pos)->bool:
#     return ins[pos+1]>=ins[pos]+lr