with open('breedflip.in',"r") as fin:
    (n,a,b)=fin.readlines()
t=[i for i in range(int(n)) if b[i]!=a[i]] # list of indices to transform
c=1 # count
for i in range(len(t)-1):
    c+=int(t[i]+1!=t[i+1])
with open("breedflip.out","w") as fout:
    fout.write(str(c))