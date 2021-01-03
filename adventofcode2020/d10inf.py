# part 2 is not my work. Look further for more details. All code that is not my work ends in a #.
# I still put my working, but too slow, code below the online solution.

file=open("i10", "r")
global ins
ins=list(map(int,[x[:-1] for x in file.readlines()]))
file.close()
ins=[0]+sorted(ins)+[max(ins)+3]

jolt=[0,0] #1 jolt, 3 jolts
diffs=[]

for x in range(len(ins)-1):
    if ins[x+1]-ins[x]==1:
        jolt[0]+=1
        diffs.append(1)
    elif ins[x+1]-ins[x]==3:
        jolt[1]+=1
        diffs.append(3)

# part 1 answer 1885
print(jolt[0]*jolt[1])

# NOTE: Part 2: was not able to solve well. I cheated by going online. Below is my attempt at
# solving the puzzle, but their time complexities were way too high to be practical. Originally, I thought they
# were infinite loops, but testing the algorithm on a small set revealed it not to be so.
# a feasible-running solution can be found, starting at line 11 in better_sols.py

def works(l) -> bool:
    for x in range(len(l) - 1):
        temp = l[x + 1] - l[x]
        if temp >3 or temp<1:
            return False
    return True

def recurse(l: list) -> list:
    if not (l[0]==0 and l[-1]==max(ins) and works(l)):
        return []
    # is a valid set of adapters
    res=[l]
    for removedindex in range(1,len(l)-1):
        temp=l[:removedindex]+l[removedindex+1:]
        res+=recurse(temp)
    return res

print(len(set(list(map(tuple,recurse(ins))))))

# the above print statement and 2 functions would work given a short list or world-class memory + world-class CPU power