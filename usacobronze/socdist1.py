# either a goes in the middle of the biggest hole and b goes in the middle of the biggest
# or they both go into the same hole
with open("socdist1.in","r") as fin:
    n,s=fin.readlines()
s=s[:-1]
n=int(n)
# add a third of 0 to each side to test the m
def ceildiv(x,y):
    xy=x//y
    return xy+(int(xy!=x/y))
# same hole, but at the edge
th=s
if n-th.rfind("1")>2:
    th+="0"*((int(n)-("1"+s).rfind("1"))//2)
if th.find("1")>1:
    th="0"*((s+"1").find("1")//2)+th
# same hole
d=-1
zl=[0]
print(th)
for x in th:
    if x=="1":
        zl+=[0]
    else:
        zl[-1]+=1
zl.sort()
print(zl)
a=zl.pop()
zl.append(a//3)
zl.append(a//3)
zl.append(a//3)

d=max(d,max(zl))
print(d)
# different holes
th=s
th="0"*((int(n)-("1"+s).rfind("1")))+s+"0"*((s+"1").find("1"))+th

zl=[0]
for x in th:
    if x=="1":
        zl+=[0]
    else:
        zl[-1]+=1
print(zl)
zl.sort()
a=zl.pop()
zl.append(a//2)
zl.append(a//2)
zl.sort()
a=zl.pop()
zl.append(a//2)
zl.append(a//2)
d=max(d,max(zl))
with open("socdist1.out","w") as fout:
    fout.write(str(d))

# for i in range(1,16):
#     f=open("socdist1_bronze_open20/{}.in".format(i), "r")
#     x=f.readlines()[1][:-1]
#     f.close()
#     print(x,end='\n')
#     g=open("socdist1_bronze_open20/{}.out".format(i), "r")
#     y=g.readlines()[0][:-1]
#     g.close()
#     print(y)
#
# def getres(x: str):
#     res=[0]
#     for y in x:
#         if y=='0':
#             res[-1]+=1
#         else:
#             res.append(0)
#     res.sort(reverse=True)
#     try:
#         while True:
#             res.remove(0)
#     except: pass
#
# def getBiggestGap(groups0):
#     return sorted(groups0)[-1]
#
#
# for i in range(1,16):
#     f=open("socdist1_bronze_open20/{}.in".format(i), "r")
#     x,y=f.readlines()
#     x=x[:-1]
#     y=y[:-1]
#     f.close()
#     res=getres(x)
#
#     # biggest gap; leftmost
#     # biggest gap; rightmost
#     # biggest gap; second biggest gap
#     # both in largest gap
#     # leftmost; rightmost
#     answers=[]
#     i=y
#     if i[0]=="0":
#         i="1"+i[1:]
#         #look for biggest gap
#         ideal0=getBiggestGap(getres(i))//2+getBiggestGap(getres(i))%2
#         zerocount=0
#         place=-1
#         for j in range(len(i)):
#
#             if zerocount==ideal0:
#                 place=j
#                 break
#
#             if j=="0": zerocount+=1
#             else: zerocount=0
#         i[place]='1'
#         answers.append(i)
#         #look at rightmost gap
#         i='1'+y[1:]
#         if i[-1]=='0':
#             i[-1]='1'
#             answers.append(i)
#     if i[-1]=='0':
#         i=i[:-1]+'1'
#         answers.append(i)
#         ideal0 = getBiggestGap(getres(i)) // 2 + getBiggestGap(getres(i)) % 2
#         zerocount = 0
#         place = -1
#         for j in range(len(i)):
#
#             if zerocount == ideal0:
#                 place = j
#                 break
#
#             if j == "0":
#                 zerocount += 1
#             else:
#                 zerocount = 0
#         i[place] = '1'
#         answers.append(i)
#
#     #look at same slot and
#     z=getBiggestGap(res)
#     ideal0a=(z+1)//3
#     ideal0b=(z-ideal0a)//2+(z-ideal0a)%2+ideal0a
#     i=y
#     i[ideal0a]='1'
#     i[ideal0b]='1'
#     answers.append(i)
#
#     # biggest; next-biggest
#
#     i=y
#     for m in range(2):
#         ideal0 = getBiggestGap(getres(i)) // 2 + getBiggestGap(getres(i)) % 2
#         zerocount = 0
#         place = -1
#         for j in range(len(i)):
#
#             if zerocount == ideal0:
#                 place = j
#                 break
#
#             if j == "0":
#                 zerocount += 1
#             else:
#                 zerocount = 0
#         i[place] = '1'
#     answers.append(i)
#
#     print(answers)



#     res=[0]
#     for y in x:
#         if y=='0':
#             res[-1]+=1
#         else:
#             res.append(0)
#     res.sort(reverse=True)
#     try:
#         while True:
#             res.remove(0)
#
#     except:
#         pass
#     try:
#         score=res[1]
#         print((score - 1)//2)
#     except:
#         if x.count('1')==2:
#             score=res[0]//2
#             print(score)
#         elif x.count('1')==1:
#             score=(res[0]-1)//2
#             print(score)
#         else:
#             score=res[0]
#             print(score-1)
#


# print(x)
# print(res)
# try:
#     print((res[1]-1)//2+1)
# except:
#     print(res[0]//3+1)