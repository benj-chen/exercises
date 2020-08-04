n=int(input())
e=list(map(int,input().split()))
r=0
for x in range(1,n):
    if e[x]<e[x-1]:
        r+=e[x-1]-e[x]
        e[x]=e[x-1]
print(r)