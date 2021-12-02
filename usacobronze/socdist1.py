# A terrible new disease, COWVID-19, has begun to spread among cows worldwide. Farmer John is trying to take as many precautions as possible to protect his herd from infection.
# Farmer John's barn is a long narrow building containing N stalls in a row (2≤N≤105). Some of these stalls are currently occupied by cows, and some are vacant. Having read about the importance of "social distancing", Farmer John wants to maximize D, where D is the distance between the closest two occupied stalls. For example, if stalls 3 and 8 are the closest that are occupied, then D=5.
#
# Two new cows recently joined Farmer John's herd and he needs to decide to which formerly-unoccupied stalls they should be assigned. Please determine how he can place his two new cows so that the resulting value of D is still as large as possible. Farmer John cannot move any of his existing cows; he only wants to assign stalls to the new cows.
#
# INPUT FORMAT (file socdist1.in):
# The first line of input contains N. The next line contains a string of length N of 0s and 1s describing the sequence of stalls in the barn. 0s indicate empty stalls and 1s indicate occupied stalls. The string has at least two 0s, so there is at least enough room for two new cows.
# OUTPUT FORMAT (file socdist1.out):
# Please print the largest value of D (the closest distance between two occupied stalls) that Farmer John can achieve after adding his two new cows in an optimal fashion.
# SAMPLE INPUT:
# 14
# 10001001000010
# SAMPLE OUTPUT:
# 2
# In this example, Farmer John could add cows to make the occupancy string look like 10x010010x0010, where x's indicate the new cows. In this case D=2. It is impossible to add the new cows to achieve any higher value of D.
# either a goes in the middle of the biggest hole and b goes in the middle of the biggest
# or they both go into the same hole
with open("socdist1.in","r") as fin:
    n,s=fin.readlines()
s=s[:-1]
n=int(n)
d=-1

def getSpaces(s):
    res=[0]
    for x in s:
        if x=="1":
            res+=[0]
        else:
            res[-1]+=1
    # rid all zero's
    while 0 in res:
        res.remove(0)
    return res
# same hole
def holesplit(spaces):
    spaces.sort()
    p=spaces.pop()
    div = (p + 1) // 2
    spaces.extend((div, p - div))
    return spaces
spaces=getSpaces(s)
spaces.sort()
p=spaces.pop()

div = (p) // 3
spaces.extend((div, div,p-div-div))
d=max(d,min(spaces))
# biggest hole, biggest hole
spaces=getSpaces(s)

for x in range(2):
    spaces=holesplit(spaces)
d=max(d,min(spaces))
if s[-1]=="0":
# right, biggest hole
    S=s[:-1]+"1"
    spaces=holesplit(getSpaces(S))
    d=max(d,min(spaces))
if s[0]=="0":
# left, biggest hole
    S="1"+s[1:]
    spaces = holesplit(getSpaces(S))
    d = max(d, min(spaces))
if s[0]=="0" and s[-1]=="0":
    print("edge edge")
    S="1"+s[1:-1]+"1"
    spaces = getSpaces(S)
    d = max(d, min(spaces)+2)
# right, left
# # add a third of 0 to each side to test the m
# def ceildiv(x,y):
#     xy=x//y
#     return xy+(int(xy!=x/y))
# # same hole, but at the edge
# th=s
# if n-th.rfind("1")>2:
#     th+="0"*((int(n)-("1"+s).rfind("1"))//2)
# if th.find("1")>1:
#     th="0"*((s+"1").find("1")//2)+th
# # same hole
# d=-1
# zl=[0]
# print(th)
# for x in th:
#     if x=="1":
#         zl+=[0]
#     else:
#         zl[-1]+=1
# zl.sort()
# print(zl)
# a=zl.pop()
# zl.append(a//3)
# zl.append(a//3)
# zl.append(a//3)
#
# d=max(d,max(zl))
# print(d)
# # different holes
# th=s
# th="0"*((int(n)-("1"+s).rfind("1")))+s+"0"*((s+"1").find("1"))+th
#
# zl=[0]
# for x in th:
#     if x=="1":
#         zl+=[0]
#     else:
#         zl[-1]+=1
# print(zl)
# zl.sort()
# a=zl.pop()
# zl.append(a//2)
# zl.append(a//2)
# zl.sort()
# a=zl.pop()
# zl.append(a//2)
# zl.append(a//2)
# d=max(d,max(zl))
with open("socdist1.out","w") as fout:
    fout.write(str(d-1))

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