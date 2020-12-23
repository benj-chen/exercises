def setup(func,expr):
    while "(" in expr:
        pend=expr.find(")") # pend: the index of an ending parenthesis
        pstart=expr[:pend].rfind("(") # pstart: the index of the starting parenthesis corresponding to pend
        expr=expr[:pstart]+str(func(expr[pstart+1:pend]))+expr[pend+1:]
    return expr
# use recursion to deal with the parentheses
def p1(expr:str) -> int:
    esep=setup(p1,expr).split()
    res=int(esep[0])
    for x in range(1,len(esep),2): res=eval(str(res)+esep[x]+esep[x+1])
    return res

def p2(expr: str)-> int:
    esep=setup(p2,expr).split()
    for x in range(len(esep)):
        if esep[x]=="+":
            esep[x-1]="("+esep[x-1]
            esep[x+1]+=")"
    return p1(' '.join(esep))
with open('dec18input','r') as file:
    inputs=file.readlines()
# part 1 answer 12956356593940
print(sum(map(p1,inputs)))

# part 2 answer 94240043727614
print(sum(map(p2,inputs)))