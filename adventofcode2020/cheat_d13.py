# part 2 is not my work. Look further for more details. All code that is not my work ends in a #.
file=open("dec13input","r")
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

# part 2: CHEATED! THIS IS NOT MY WORK! More after the printing of the solution
# code courtesy of reddit user Hercule608: https://www.reddit.com/user/Hercule608/
# my work starts at line 78 and ended at line 14.
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

    print(divs) #

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
        print(divs) #
    # part 2 answer 842186186521918
    print(divs[0][1]) #

# my attempt below. Too slow to produce the answer, but probably produces the correct one.
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