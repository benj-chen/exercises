with open("i19","r") as file:
    inputs=[x[:-1] for x in file.readlines()]
n=inputs.index('')
r,m=[x.split(": ") for x in inputs[:n]],inputs[n+1:]
del inputs,n

r={int(x[0]):x[1] for x in r}
# r[8]="42 | 42 8"
# r[11]="42 31 | 42 11 31"
print(r)
def get_len(rule:int) -> int:
    if '"' in r[rule]:
        return 1
    a=list(map(int,r[rule].split(' | ')[0].split()))
    totalcount=0
    for x in a:
        totalcount+=get_len(x)
    return totalcount
def match(ab:str,rule:int=0)->bool:
    # will get in an infinite loop if a rule loops to a rule that goes back to the first rule
    if '"' in r[rule]: # base case
        # ab is of length 1
        return ab==r[rule][1]

    # decode the rule
    rules=[list(map(int,x.split())) for x in r[rule].split(' | ')]
    # rules: a list of lists. If one of a list matches, then return True
    for ruleOr in rules:
        prevpart=0
        works=True
        for part in ruleOr:
            # part is an int pertaining to a rule.
            curpart=get_len(part)+prevpart
            works=works and match(ab[prevpart:curpart],part)
            prevpart=curpart
        if works:
            return True
    return False
length0=get_len(0)
match0=0
for x in m:
    match0+=int(match(x,0)) if len(x)==length0 else 0
# part 1 answer 213
print(match0)
# change rule 8 and 11 as follows:
# 8 from 8: 42 ||||to|||| 8: 42 | 42 8
# 11 from 11: 42 31 ||||to|||| 11:

# change get_len to return the potential lengths up to the maximum length of any given message.