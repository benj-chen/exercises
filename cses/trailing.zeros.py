# https://cses.fi/problemset/task/1618
#from internet
c=0
n=int(input())
i=5
while n / i > 0:
    c += n//i
    i *= 5

print(c)
"""
# mine is too slow for 3 cases
n=int(input())+1

e,x,c=list(range(5,n,5)),1,0

while x<n:
    c+=len(e[x-1::x])
    x*=5
print(c)
"""