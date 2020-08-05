# https://cses.fi/problemset/task/1622
#maximum 8 letters long, meaning only 8 letters max(this is great! I can use ints to represent the letters)
s=input()
f=[]
# translate letters to ints
order={}
for x in range(len(set(s))):
    order[list(set(s))[x]]=x
e=''
for x in s:
    e+=str(order[x])
# find all the configurations

for x in range(int(''.join(list(reversed(sorted(e)))))+1):
    d=str(x).zfill(len(e))
    if sorted(d)==sorted(e):
        f.append(d)

#swap key and value to translate back to letters
k=order.items()
order={}
for x in k:
    order[str(x[1])]=x[0]
print(len(set(f)))
g=[]
for x in list(set(f)):
    temp=''
    for y in x:
        temp+=(str(order[y]))
    g.append(temp)
for x in sorted(g):
    print(x)