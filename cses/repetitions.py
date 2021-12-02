# https://cses.fi/problemset/task/1069
Str=input()
Max=1
prevmax=1

cur=Str[0]
for x in range(1,len(Str)):
    if cur==Str[x]:
        Max+=1
    else:
        prevmax=max((Max,prevmax))
        Max=1
        cur=Str[x]
print(max(Max,prevmax))
