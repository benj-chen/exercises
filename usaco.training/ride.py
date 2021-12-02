"""
ID: benjche1
LANG: PYTHON3
TASK: ride
"""
import string
fin=open('ride.in','r')
fout=open('ride.out','w')
a,b=fin.readlines()
e={}
for x in range(1,27):
    e[string.ascii_uppercase[x-1]]=x

a1=1
a2=1
for x in a.strip():
    a1*=e[x]
for x in b.strip():
    a2*=e[x]
x="GO" if a1%47==a2%47 else "STAY"
fout.write(x+'\n')
fin.close()
fout.close()