from random import randint
res=[]
for x in range(100):
    res.append(randint(0,3))
print(res.count(0))
print(res.count(1)+res.count(2))
print(res.count(3))