import os
print(os.getcwd())
with open("i24","r") as f:
    ins=[g for g in f.readlines()]
# the first step is to break down each line into the individual steps
print(ins)
helperdict={
    ("ne","w"):"nw",
    ("se","w"):"sw",
    ("e","nw"):"ne",
    ("e","sw"):"se",
    ("nw","sw"):"w",
    ("ne","se"):"e",
}
def solve_helper(sol1, sol2,step):
    
    helper=tuple(sorted((sol1,sol2)))
    if helper in helperdict:
        # replace
        while helper[0] in step and helper[1] in step:
            step.remove(helper[0])
            step.remove(helper[1])
            step.append(helperdict[helper])
    else:
        # don't replace
        while helper[0] in step and helper[1] in step:
            step.remove(helper[0])
            step.remove(helper[1])
def solve_recur(step):
    prev=sorted(step)
    solve_helper("ne","sw",step)
    solve_helper("nw","se",step)
    solve_helper("ne","w",step)
    solve_helper("se","w",step)
    solve_helper("nw","e",step)
    solve_helper("sw","e",step)
    solve_helper("nw","sw",step)
    solve_helper("ne","se",step)
    solve_helper("e","w",step)
    
    if prev==sorted(step):
        return sorted(step)
    return solve_recur(step)
    
steps={} # list of lists
for x in ins:
    # can't do for x in range(len(x)) because some are two/one letters long
    step=[]
    y=0
    while y<len(x)-1:
        if x[y] in "ns":
            step.append(x[y:y + 2])
            y+=1
        else:
            step.append(x[y])
        y+=1
    # determine shortcuts, for example, "ne sw" would just become "" because they take one back to the ref point
    # another example, "neesw" would become "e", once again because "ne" and "sw" cancel out each other
    #order is important

    step=tuple(solve_recur(step))
    steps[step]=(True if step not in steps else not steps[step])


# after this, compare to each other and see if a, potentially in a different order, could match b, because the seqs could
# be shuffled but would still go to the same place.

# s=set()
# for x in steps:
#     if x in s:
#         s.remove(x)
#     else:
#         print(x)
#         s.add(x)
# print(len(s))
print(sum(steps.values()))
ADJ=("e","w","nw","ne","sw","se")
for x in range(100):
    switch=set()
    for y in steps:
        ct=0
        for z in ADJ:
            a=list(y)+[z]
            b=tuple(solve_recur(a))
            if b in steps:
                ct+=steps[b]
        if steps[y]:
            # black tile
            if ct==0 or ct>2:
                switch.add(y)
        else:
            if ct==2:
                switch.add(y)
    for c in switch:
        steps[c]=not steps[c]
    print(sum(steps.values()))
# use a set to hold all of the values that require switching. If a value is already in there, remove it.
#395 too high