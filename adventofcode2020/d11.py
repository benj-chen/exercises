dirs = [(dx, dy) for dx in range(-1, 2) for dy in range(-1, 2) if dx or dy] # dirs creates the different index
# differences relative to the current seat
def solution(inputs, typeSol: int, maxOccEmpty: int): # inputs is the puzzle input
    """
    typeSol: int: either 1 or 2, to access either part
    maxOccEmpty: int: max occupied seat to change from occupied to non-occupied (4 or 5)
    """
    ins = list(map(list, inputs))
    # initially, ins is the input. In the first iteration of the while loop, ins is the safe copy
    # of the inputs while res is the one that undergoes the seat switching process. After, ins becomes res to let
    # res become the next guinea pig, so to speak. In other words, for the most part, ins is the previous version
    def getOcc(x,y):
        occ_count = 0
        if typeSol==1:
             # occ_count: how many occupied seats are either up, down, left, right, up-r, up-l, down-r, or
            # down-l of the current seat in question
            for z in dirs:
                try:
                    assert x + z[0] >= 0 and y + z[1] >= 0
                    if ins[x + z[0]][y + z[1]] == "#":
                        occ_count += 1
                except:
                    continue

        else:
            for z in dirs:
                temp = z  # this will create a copy because z is a tuple
                while x + temp[0] >= 0 and y + temp[1] >= 0:
                    try:
                        if ins[x + temp[0]][y + temp[1]] == "#":
                            occ_count += 1
                            break
                        if ins[x + temp[0]][y + temp[1]] == "L":
                            break
                    except:
                        break
                    temp = (temp[0] + z[0], temp[1] + z[1])
        return occ_count

    while True:
        res = [x.copy() for x in ins]
        for x in range(len(ins)):
            for y in range(len(ins[x])):
                if ins[x][y] == ".":
                    continue
                occ_count = getOcc(x,y)
                # occ_count: how many occupied seats are either up, down, left, right, up-r, up-l, down-r, or down-l
                # of the current seat in question

                if ins[x][y] == "L" and not occ_count:
                    res[x][y] = "#"
                    continue
                # now it has to be occupied
                if occ_count >= maxOccEmpty:
                    res[x][y] = "L"
        if res == ins:
            ct = 0
            for x in ins: ct += x.count("#")
            # answer
            return ct
        # update the copy
        ins = [x.copy() for x in res]

file=open('dec11input','r')
inputs=[(x[:-1]) for x in file.readlines()]
file.close()
# part 1 answer
print(solution(inputs,1,4))
# part 2 answer 2121
print(solution(inputs,2,5))