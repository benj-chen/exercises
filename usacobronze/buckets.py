with open("buckets.in","r") as fin:
    ins=fin.readlines()
b=None
l=None
r=None
for i in range(len(ins)):
    x=ins[i]
    bloc=x.find("B")
    lloc=x.find("L")
    rloc=x.find("R")
    if bloc+1:
        b=(i,bloc)
    if lloc+1:
        l=(i,lloc)
    if rloc+1:
        r=(i,rloc)
    if b and r and l:
        break

# b,l,r coordinate formats: (vertical distance, horizontal distance)
xd,yd=b[0]-l[0],b[1]-l[1]

with open("buckets.out","w") as fout:
    fout.write(str(sum(map(abs, (xd, yd))) + [-1,1][False if xd and yd else \
        (yd and r[0]==b[0] and r[1] in range(b[1],l[1]) or r[1] in range(l[1],b[1])) or\
         (xd and r[1]==b[1] and r[0] in range(b[0],l[0]) or r[0] in range(l[0],b[0]))]))
# boolean indexing: 0 if False, 1 if True