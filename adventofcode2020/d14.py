file=open("i14", "r")
inputs=[x.split(' = ') for x in file.readlines()]
file.close()
ins=[x[:] for x in inputs]
lastmask=inputs.pop(0)[1][:-1]

res=dict()
for x in inputs:
    if "mask" in x[0]:
        lastmask=x[1][:-1]
        continue

    index=x[0][4:-1]
    value=bin(int(x[1]))[2:].zfill(36)
    res[index]='0b'
    for z in range(36):  # 36 is the given length of mask
        if lastmask[z] == "X":
            res[index] += value[z]
        elif lastmask[z] == "1":
            res[index] += '1'
        else:
            res[index] += '0'
    res[index] = int(res[index], 2)

# part 1 answer 3059488894985
print(sum(res.values()))

lastmask=ins.pop(0)[1][:-1]

res=dict()

def gen_vals(toEval: int,toFloat: list):
    toFloat=toFloat[:]
    # toFloat: list of negative indexes to change.

    if not toFloat: # nothing left to switch
        return [toEval]
    res=[]

    for x in range(len(toFloat)):
        y=toFloat.pop(0)

        res.extend(gen_vals((2**y)+toEval,toFloat))
        res.extend(gen_vals(toEval, toFloat))

    return res

for x in ins:
    if "mask" in x[0]:
        lastmask=x[1][:-1]
        continue
    index=x[0][4:-1]
    value=bin(int(str(index)))[2:].zfill(36)
    place='0b'
    placestogo=[]
    for z in range(36):
        if lastmask[z] == "0":
            place += value[z]
        elif lastmask[z] == "X":
            place+='0'
            placestogo.append(abs(z-35))
        else:
            place+=lastmask[z]
    result=int(x[1])
    for y in gen_vals(int(place,2),placestogo):
        res[y]=result
# part 2 answer 2900994392308
print(sum(res.values()))