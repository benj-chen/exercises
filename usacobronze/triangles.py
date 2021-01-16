with open("triangles.in","r") as fin:
    a=[tuple(map(int,i.split())) for i in fin.readlines()][1:]

# test everything
# the triangle area written should be double the actual area, making it just bh.
with open("triangles.out","w") as fout:
    fout.write(str(max(abs((i[1]-j[1])*(j[0]-k[0])) for k in a for j in a for i in a if i[0]==j[0] and j[1]==k[1])))