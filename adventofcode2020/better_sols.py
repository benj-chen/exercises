file=open("i10", "r")
global ins
ins=list(map(int,[x[:-1] for x in file.readlines()]))
file.close()
ins=[0]+sorted(ins)+[max(ins)+3]
# Day 10, part 2 code courtesy of reddit user masslessneutrino: https://www.reddit.com/user/masslessneutrino/
# unoriginal code lines end in a comment #
# I did my own solution in c++ that is very good, so this is strictly for python.
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
