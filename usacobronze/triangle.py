
"""
Farmer John would like to create a triangular pasture for his cows.
There are N fence posts (3≤N≤100) at distinct points (X1,Y1)…(XN,YN) on the 2D map of his farm.
He can choose three of them to form the vertices of the triangular pasture as long as
one of the sides of the triangle is parallel to the x-axis and another side is parallel to the y-axis.

What is the maximum area of a pasture that Farmer John can form?
It is guaranteed that at least one valid triangular pasture exists.

INPUT FORMAT (file triangles.in):
The first line of the input contains the integer N.
Each of the next N lines contains two integers Xi and Yi,
each in the range −104…104 inclusive, describing the location of a fence post.
OUTPUT FORMAT (file triangles.out):
As the area itself is not necessarily an integer
output two times the maximum area of a valid triangle formed by the fence posts.
SAMPLE INPUT:
4
0 0
0 1
1 0
1 2
SAMPLE OUTPUT:
2
Posts at (0,0), (1,0), and (1,2) form a triangle of area 1. Thus, the answer is 2⋅1=2.
There is only one other triangle, with area 0.5.
"""

#This one doesn't work. Some problems with the return statement, will need to look at it again
def removeduplicates(e):
    ret=[]
    for x in e:
        y=sorted(x)
        if y in ret: continue
        ret.append(y)
    return ret

"""master
def bigtri(testfile):
    file = open('triangles_bronze_feb20/' + testfile)
    coordinates=[[4],
[0,0],
[0,1],
[1,0],
[1,2]]
    x=[]
    y=[]
    for e in range(1,len(coordinates)):
        for f in range(1,len(coordinates)):
            if coordinates[e][0]==coordinates[f][0] and e!=f:
                y.append([coordinates[e],coordinates[f]])
            if coordinates[e][1]==coordinates[f][1] and e!=f:
                x.append([coordinates[e], coordinates[f]])

    (x,y)=map(removeduplicates,[x,y])
    print(x)
    print(y)
    biggest=0
    for e in y:
        for f in x:
            res=abs(f[0][0]-f[1][0])*(abs(e[0][1]-e[1][1]))
            if res>biggest: biggest=res
    return biggest
print(bigtri('1.in'))
"""
def bigtri(testfile):
    file = open('triangles_bronze_feb20/' + testfile)
    coordinates=[]
    for x in file.readlines():
        if ' ' in x:
            coordinates.append(list(map(int,x.split())))
            continue
        coordinates.append(int(x))
    print(coordinates)
    x=[]
    y=[]
    for e in range(1,len(coordinates)):
        for f in range(1,len(coordinates)):
            if coordinates[e][0]==coordinates[f][0] and e!=f: y.append([coordinates[e],coordinates[f]])
            if coordinates[e][1]==coordinates[f][1] and e!=f: x.append([coordinates[e], coordinates[f]])

    (x,y)=map(removeduplicates,[x,y])
    print(x)
    print(y)
    biggest=0
    for e in y:
        for f in x:
            res=abs(f[0][0]-f[1][0])*(abs(e[0][1]-e[1][1]))
            if res>biggest: biggest=res
    return biggest
print(bigtri('2.in'))


"""
def bigtri(testfile):
    file = open('triangles_bronze_feb20/' + testfile)
    coordinates=[(x.strip().split()) for x in file.readlines()]
    file.close()
    print(coordinates)
    x=[]
    y=[]
    for e in range(1,len(coordinates)):
        for f in range(1,len(coordinates)):
            if coordinates[e][0]==coordinates[f][0] and e!=f:
                y.append([list(map(int,coordinates[e])),list(map(int,coordinates[f]))])
            if coordinates[e][1]==coordinates[f][1] and e!=f:
                x.append([list(map(int,coordinates[e])),list(map(int,coordinates[e]))])

    (x,y)=map(removeduplicates,[x,y])
    print(x)
    print(y)
    biggest=0
    for e in y:
        for f in x:
            res=abs(f[0][0]-f[1][0])*(abs(e[0][1]-e[1][1]))
            if res>biggest: biggest=res
    return biggest
print(bigtri('1.in'))
"""