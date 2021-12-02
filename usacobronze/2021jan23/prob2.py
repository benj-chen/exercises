n=int(input())
ord=list(map(lambda l: l%2,map(int,input().split())))
# the first group should be even, second odd, etc.
# even sums up to 0, odd sums up to 1
# a group that adds to 5 produces a set of even and odd

z=ord.count(0)
o=ord.count(1)
a=o-z
if a>0: #less evens than odds
    dm = divmod(a, 3)
    if not o%2:
        print(z*2+(dm[0]*2)+bool(dm[1]))
    else:
        print(z*2+(dm[0]*2)-bool(dm[1]))
else:
    print(o*2+bool(z-o))