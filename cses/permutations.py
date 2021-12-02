# cses.fi/problemset/task/1070
n=int(input())
r=list(range(1,n+1))
if n==1: print(1)
if n<=3: print("NO SOLUTION")
if n==4: print('3 1 4 2')
if n>4:
    for x in r[::2]+r[1::2]:
        print(x,end=' ')