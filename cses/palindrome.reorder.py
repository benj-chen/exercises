n=input()
e={}
for x in sorted(n):
    try:e[x]+=1
    except:e[x]=1
if len(e)==1: print(n);exit()
odd=0
#There has to be either 0 or 1 odd values of any letter
d=None
for x in e:
    if e[x]%2==1: odd+=1;d=x
odd=True if odd<2 else False

if not odd: print("NO SOLUTION");exit()
res=''
for x in e:
    if x==d: continue
    res=res[:len(res)//2]+x*e[x]+res[len(res)//2:]
if d: res=res[:len(res)//2]+d*e[d]+res[len(res)//2:]
print(res)