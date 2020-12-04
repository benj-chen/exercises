file=open("dec2input","r")
inputs=[]
for x in file.readlines():
    i,j,k=x.split()
    inputs.append([tuple(int(y) for y in i.split('-')),j[:-1],k])
file.close()
count=0
for i in inputs:
    a,b,c=i
    bcount=c.count(b)
    if bcount in range(a[0],a[1]+1):
        count+=1

# Part 1 answer 434: print(count)
count=0
for x in inputs:
    a,b,c=x
    if (c[a[0]-1]==b and c[a[1]-1]!=b) or (c[a[0]-1]!=b and c[a[1]-1]==b):
      count+=1
# Part 2 answer 509: print(count)