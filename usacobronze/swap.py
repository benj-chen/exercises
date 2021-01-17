# passes 9/10 test cases :(
with open("swap.in","r") as fin:
    [n,k],[a1,a2],[b1,b2]=[list(map(int,x.split())) for x in fin.readlines()]
result=list(range(1,n+1))
results=[]
a1-=1
b1-=1
while result not in results:
    results.append(result[:])
    result[a1:a2]=list(reversed(result[a1:a2]))
    result[b1:b2]=list(reversed(result[b1:b2]))


# 0th index is the base case
with open("swap.out","w") as fout:
    fout.write('\n'.join(map(str,results[k%len(results)]))+'\n')

with open("swap.in","r") as fin:
    [n,k],[a1,a2],[b1,b2]=[list(map(int,x.split())) for x in fin.readlines()]