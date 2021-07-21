m,n=map(int,input().split()) # alternatively, m,n = input().split(), then convert m and n to ints
ans=0 # Python doesn't worry about int overflowing
for i in range(m,n+1):
   ans+=i
print(ans)