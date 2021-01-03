# SAVE POINT LMAO

with open("i21","r") as fin: inputs=sorted([[sorted(z.split(", ")),y.split()] for y,z in [x[:-2].split(" (contains ") for x in fin.readlines()]])

# every allergen in there has exactly one original ingredient. Every ingredient has exactly one or zero allergens.


solved={(x[0][y]): False for x in inputs for y in range(len(x[0]))}
poss_ingr={(x[0][y]): [set(),[],False] for x in inputs for y in range(len(x[0]))}
# while loop?
# use a for loop to set up, then weed out from there...
for x in inputs:
    for ing in x[0]:
        for enc in x[1]:
            if enc in poss_ingr[ing][0]:
                poss_ingr[ing][1].append(enc)
            poss_ingr[ing][0].add(enc)
# weed out
for x in poss_ingr:
    if len(poss_ingr[x][0])==1:
        poss_ingr[x][1]=list(poss_ingr[x][0])
    if len(poss_ingr[x][1])==1:
        poss_ingr[x][0] = []
        poss_ingr[x][2]=True
        # take out from everything else
        for y in poss_ingr:
            if poss_ingr[y][2]:
                continue
            for z in range(len(poss_ingr[y])-1):
                try:
                    poss_ingr[y][z].remove(poss_ingr[x][1][0])
                except:
                    pass

print(poss_ingr)
for x in poss_ingr:
    if not poss_ingr[x][2]:
        print(poss_ingr[x])
# begin second screen


print(poss_ingr)
allergens=[poss_ingr[x][1][0] for x in poss_ingr if poss_ingr[x][2]]
print(allergens)
print(inputs)
counter=0
for x in inputs:
    # consider x[1]
    for z in allergens:
        counter-=x[1].count(z)
    counter+=len(x[1])
print(counter)
# 2790 too high
# print(solved)
# toStart=0
# counter=0
# while counter<len(solved):
#
#     toConsider=list(solved.keys())[counter]
#     for x in range(toStart,len(inputs)):
#
#         if toConsider not in inputs[x][0]:
#             break
#         # do some stuff
#         for y in inputs[x][1]:
#             if y in poss_ingr[toConsider][0]:
#                 poss_ingr[toConsider][1].append(y)
#             poss_ingr[toConsider][0].add(y)
#         # add stuff to the set
#     toStart=x
#
#     if len(poss_ingr[toConsider][1])==1:
#         solved[toConsider]=True
#         foreign=poss_ingr[toConsider][1][0]
#         poss_ingr[toConsider]=set(),[foreign,foreign]
#
#         print(foreign)
#         # remove that ingredient from all other places in possible ingredients
#         for x in poss_ingr:
#             for y in range(len(poss_ingr[x])):
#                 print(poss_ingr[x][y],'   .')
#                 if foreign in poss_ingr[x][y]:
#                     poss_ingr[x][y].remove(foreign)
#
#     toConsider=inputs[toStart][0]
#     counter+=1
#     print(poss_ingr)
# # end of while loop
# end of save





# all of the code here that ends in a single-line comment # has been pulled from another online source. The source
# for a given line of code can be found above it, in a comment of its own.

file=open("i10", "r")
global ins
ins=list(map(int,[x[:-1] for x in file.readlines()]))
file.close()
ins=[0]+sorted(ins)+[max(ins)+3]
# Day 10, part 2 code courtesy of reddit user masslessneutrino: https://www.reddit.com/user/masslessneutrino/
# unoriginal code lines end in a comment #
def slow_count(data, index=0):#
    data.sort() #
    count = 0 #
    if index == len(data) - 1: #
        count += 1 #
        return count #
    if index <= len(data) - 2: #
        if data[index+1] - data[index] <= 3: #
            count += slow_count(data, index+1) #
    if index <= len(data) - 3: #
        if data[index+2] - data[index] <= 3: #
            count += slow_count(data, index+2) #
    if index <= len(data) - 4: #
        if data[index+3] - data[index] <= 3: #
            count += slow_count(data, index+3) #
    return count #

def fast_count(data): #
    data.sort() #
    i = 0 #
    count = 1 #
    while i < len(data): #
        diff_one_seq = [data[i]] #
        next_i = i+1 #
        for j in range(i+1, len(data)): #
            if data[j] - data[j-1] == 1: #
                diff_one_seq.append(data[j]) #
            else: #
                next_i = j #
                break #
        count *= slow_count(diff_one_seq) #
        i = next_i #
    return count #
# part 2 answer 2024782584832
print(fast_count(ins)) #

file=open("i13", "r")
inputs=file.readlines()
file.close()

ins=inputs.copy()
ins[0]=int(ins[0])
ins[1]=[int(x) for x in ins[1].split(',') if x!="x"]

# day 13, part 2 code courtesy of reddit user Hercule608: https://www.reddit.com/user/Hercule608/
def ext_gcd(a, b): #
    x = 1 #
    y = 0 #
    x1 = 0 #
    y1 = 1 #
    a1 = a #
    b1 = b #

    while b1 > 0: #
        q = a1 // b1 #
        x, x1 = x1, x - q * x1 #
        y, y1 = y1, y - q * y1 #
        a1, b1 = b1, a1 - q * b1 #

    return x, y #

if __name__ == '__main__': # the following two lines modified for my input file
    # n = int(input())
    # t = input().split(',')
    n=ins[0]
    t=inputs[1].split(",")
    divs = [] #
    mx = [-1, -1] #
    lcm = 1 #
    for i in range(len(t)): #
        if t[i] == 'x': #
            continue #

        t[i] = int(t[i]) #

        k = i #
        k %= t[i] #
        k = t[i] - k #
        k %= t[i] #

        divs.append([int(t[i]), k]) #
        lcm *= int(t[i]) #
        if mx[0] == -1 or divs[-1][0] > mx[0]: #
            mx = divs[-1] #

    # print(divs) #

    while len(divs) > 1: #
        n1, a1 = divs[-1] #
        n2, a2 = divs[-2] #

        divs.pop() #
        divs.pop() #
        m1, m2 = ext_gcd(n1, n2) #
        x = a1 * m2 * n2 + a2 * m1 * n1 #
        x %= n1 * n2 #

        if x < 0: #
            x += n1 * n2 #
        divs.append([n1 * n2, x]) #
        # print(divs) #
    # part 2 answer 842186186521918
    print(divs[0][1]) #