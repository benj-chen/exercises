def avg(n):
    return (sum(n)-max(n)-min(n))/(len(n)-2)
def mean(n): return sum(n)/len(n)
res=[]
for x in range(5):
    res.append(float(input()))
print(mean(res))
print(avg(res))