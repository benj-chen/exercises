# https://cses.fi/problemset/task/1071
n=int(input())
ins=[list(map(int,input().split())) for x in range(n)]
for z in ins:
    y,x=z
    if x==y:
        print(x**2-x+1)
        continue
    else:
        e=x
        if x<y:
            (x,y)=(y,x)
            e+=1
        if e%2==0:
            print(x**2-2*x+1+y)
        else:
            print(x**2-y+1)