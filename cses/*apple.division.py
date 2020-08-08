# https://cses.fi/problemset/task/1623
from math import ceil
rl = lambda x: range(len(x))
n=int(input())
ns=list(map(int,input().split()))
s=sum(ns)
s1=s//2
s2=s-s1
e=sum(ns)/2
ns1=[]
for x in ns: ns1.append(e-x)
res=[]
for x in ns:
    y=False
    if x in ns1: y=x
    if x - 0.5 in ns1: y=x-0.5
    if x+0.5 in ns1: y=x+0.5
    if y:
        res.extend((x,ns1.pop(ns1.index(y))))
r1=0
r2=0
for x in res[::2]:
    r1+=x
for x in res[1::2]:
    r2+=x
print(ceil(abs(r1-r2)))