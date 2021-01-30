n,q=map(int,input().split())
s=input()
unp=[tuple(map(int,input().split())) for x in range(q)]
# def helperf(sstr):
#     # recurse, return number of steps
#     # base case: two chars
#     if len(sstr)==2:
#         return (sstr[0]!=sstr[1])+1
#     # if it's 3, recurse
#     helperf(sstr[:-1])
#     return 1
dp={'':0}
def numPaint(sstr):
    # uses the alphabet sorta.. you'll see
    if sstr in dp: return dp[sstr]
    if len(sstr)==1:
        dp[sstr]=1
        return 1
    m=min(sstr)
    if m!=sstr[0] and m!=sstr[-1]:
        i,j=sstr[:sstr.find(m)],sstr[sstr.find(m):]
        a,b=numPaint(i),numPaint(i)
        dp[i]=a
        dp[j]=b
        dp[sstr]=a+b
        return a+b
    dp[sstr]=1 + numPaint(sstr.strip(m))
    return dp[sstr]
    # l=min(sstr) # ah yes, python lets you use < to compare chars, get dunked on java
    # recursion limit damn
    # c=sstr.pop(0)
    # lowbetw=False
    # for x in range(len(sstr)):
    #     if lowbetw and sstr[x] in sstr[:x]

for x in unp:
    print(s[:x[0]-1])
    print(s[x[1]:])
    print(numPaint(s[:x[0]-1])+numPaint(s[x[1]:]))