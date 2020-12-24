with open("i19","r") as file:
    inputs=[x[:-1] for x in file.readlines()]
n=inputs.index('')
r,m=[x.split(": ") for x in inputs[:n]],inputs[n+1:]
del inputs,n
print(r)
r={int(x[0]):x[1] for x in r}
print(m)
def get_len(rule:int) -> set:
    if '"' in r[rule]:
        return {1}
    b=[list(map(int,x.split())) for x in r[rule].split(' | ')]
    totalcount=set()
    for a in b:
        count=[0]
        for x in a:
            s=get_len(x)
            if len(s)==1:
                for d in range(len(count)):
                    count[d]+=s.pop()
            else:


        totalcount.add(count)
    return totalcount
print(get_len(0))
print(get_len(0))
def match(ab:str,rule:int=0)->bool:
    # will get in an infinite loop if a rule loops to a rule that goes back to the first rule

    if '"' in r[rule]: # base case
        # ab is of length 1
        return ab==r[rule][1]
    # decode the rule
    rules=[list(map(int,x.split())) for x in r[rule].split(' | ')]
    for ruleOr in rules:
        pass
    return True

match0:int=0
# for x in m:


print(match0)