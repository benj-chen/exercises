file=open("dec9input","r")
ins=[x[:-1] for x in file.readlines()]

file.close()

PALEN=25
cur_num=-1
for pastart in range(len(ins)-PALEN): # pastart: index for start of preamble - length PALEN
    pa=list(map(int,ins[pastart:pastart+PALEN]))
    assert len(pa)==PALEN
    cur_num=int(ins[pastart+PALEN])
    notfound=True
    for i in pa:
        for j in pa:
            if i+j==cur_num:
                notfound=False
    if notfound:
        # part 1 answer 26796446
        print(cur_num)
        break

for contigstart in range(len(ins)):
    contiglist=[int(ins[contigstart])]
    extraindex=1 #initially adds the index contigstart+1, then 2 if need be, etc
    while sum(contiglist)<cur_num:
        contiglist.append(int(ins[contigstart+extraindex]))
        extraindex+=1
    if sum(contiglist)==cur_num:
        # part 2 answer 3353494
        print(min(contiglist)+max(contiglist))
        break