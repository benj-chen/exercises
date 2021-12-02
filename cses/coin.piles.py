# https://cses.fi/problemset/task/1754
#readable version
"""
n=int(input())
l=[input().split() for x in range(n)]
l=[list(map(int,x)) for x in l]
for x in l:
    if (sum(x)%3!=0) or (x[0]*2<x[1] or x[1]*2<x[0]):print("NO");continue
    print("YES")
"""
#short version:
for x in [list(map(int,x)) for x in [input().split() for x in range(int(input()))]]:
    print("NO" if (sum(x)%3!=0) or (x[0]*2<x[1] or x[1]*2<x[0]) else 'YES')