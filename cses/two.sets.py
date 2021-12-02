# https://cses.fi/problemset/task/1092
i=int(input())
l=list(range(1,i+1))
l1=[]
l2=[]
total=i*(i+1)/4

if ((i - 3) % 4 == 2) or (i % 4 == 2): print("NO");exit()
if i==3: print("YES\n2\n2 1\n1\n3");exit()
if i % 2==1:
    l1.append(l.pop(0))
    l1.append(l.pop(len(l) // 2 - 1))
    l2.append(l.pop(len(l) // 2))
even=True
t=int(total)-sum(l1)
b=l[0]+l[-1]
e=t//b
l1.extend(l[:e])
l1.extend(l[0-e:])
l2.extend(l[e:0-e])
l1=list(map(str,l1))
l2=list(map(str,l2))
print('YES\n{}\n{}\n{}\n{}'.format(len(l1),' '.join(l1),len(l2),' '.join(l2)))