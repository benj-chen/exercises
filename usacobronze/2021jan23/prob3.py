n=int(input())
c,s=list(sorted(map(int,input().split()))),list(map(int,sorted(input().split())))

d={x:[y for y in s if x<=y] for x in reversed(c)}
lens=[len(d[x]) for x in d]
prod=1
takeout=0
for x in lens:
    prod*=x-takeout
    takeout+=1
print(prod)