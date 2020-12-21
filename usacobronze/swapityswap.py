with open("swap.in","r") as fin:
    [n,k],[a1,a2],[b1,b2]=[list(map(int,x.split())) for x in fin.readlines()]
result=list(range(1,n+1))
results=[result[:]]
a1-=1
b1-=1
while True:
    result[a1:a2]=list(reversed(result[a1:a2]))
    result[b1:b2]=list(reversed(result[b1:b2]))
    if result in results:
        break
    results.append(result[:])

# 0th index is the base case
print(results)
with open("swap.out","w") as fout:
    fout.write('\n'.join(map(str,results[k%len(results)]))+'\n')