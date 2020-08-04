# https://cses.fi/problemset/task/1068

n=input()
while n!=1:
    n=int(n)
    print(n, end=' ')
    if n%2==0:
        n>>=1
        continue
    n=n*3+1
print(1)