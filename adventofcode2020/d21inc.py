with open("i21","r") as fin: inputs=sorted([[sorted(z.split(", ")),y.split()] for y,z in [x[:-2].split(" (contains ") for x in fin.readlines()]])

# every allergen in there has exactly one original ingredient. Every ingredient has exactly one or zero allergens.


solved={(x[0][y]): False for x in inputs for y in range(len(x[0]))}
poss_ingr={(x[0][y]): [[],0,False] for x in inputs for y in range(len(x[0]))}
ingredients={(x[0][y]): None for x in inputs for y in range(len(x[0]))}

# while loop?
# use a for loop to set up, then weed out from there...
for x in inputs:
    for ing in x[0]:
        poss_ingr[ing][1]+=1
        for enc in x[1]:
            poss_ingr[ing][0].append(enc)
print(poss_ingr)
print()
# weed out
# for x in poss_ingr:
#     if len(poss_ingr[x][1])>1:
#         print('what')
#     if len(poss_ingr[x][0])==1:
#         poss_ingr[x][1]=list(poss_ingr[x][0])
#     if len(poss_ingr[x][1])==1:
#         poss_ingr[x][0] = []
#         poss_ingr[x][2]=True
#         # take out from everything else
#         for y in poss_ingr:
#             if poss_ingr[y][2]:
#                 continue
#             for z in range(len(poss_ingr[y])-1):
#
#                 poss_ingr[y][z].remove(poss_ingr[x][1][0])
#
#
# print(poss_ingr)
# for x in poss_ingr:
#     if not poss_ingr[x][2]:
#         print(poss_ingr[x])
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


"""


with open("i21","r") as fin: inputs=sorted([[sorted(z.split(", ")),y.split()] for y,z in [x[:-2].split(" (contains ") for x in fin.readlines()]])

# every allergen in there has exactly one original ingredient. Every ingredient has exactly one or zero allergens.


solved={(x[0][y]): False for x in inputs for y in range(len(x[0]))}
poss_ingr={(x[0][y]): [set(),[],False] for x in inputs for y in range(len(x[0]))}
ingredients={(x[0][y]): None for x in inputs for y in range(len(x[0]))}

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
    if len(poss_ingr[x][1])>1:
        print('what')
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

                poss_ingr[y][z].remove(poss_ingr[x][1][0])


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
"""