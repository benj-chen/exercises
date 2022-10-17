s = list(map(int,input().split(',')))

for i in range(0,len(s),4):
    if s[i]==99:
        print(s[0])
        break
    if s[i]==1:
        s[s[i+3]] = s[s[i+1]]+s[s[i+2]]
    if s[i]==2:
        s[s[i+3]] = s[s[i+1]]*s[s[i+2]]