c,n = map(int,input().split())
ls = []
for i in range(n):
    num = 0
    for j in input():
        num <<= 1
        if j == "G":
            num += 1
    ls.append(num)
ans = [0]*n
for i in range(n):
    for j in range(i+1,n):
        q = bin(ls[i]^ls[j]).count('1')
        ans[i] = max(ans[i],q)
        ans[j] = max(ans[j],q)
for i in ans: print(i)
