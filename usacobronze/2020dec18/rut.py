# My working solution to "Stuck in a Rut" USACO problem from 2020 December 18. Not submitted on time in the 4 hour window - completed afterwards.
# For my not working solution, see "rut_failed.py"
class Cow:
    def __init__(self,dir,x,y):
        self.dir=dir=="E" # direction is True if the cow goes East, False if North
        self.x=x
        self.y=y
        self.u=1000000000 # (u)pper limit, x or y depending on dir. This is the distance that self goes until stopped.
            # Default to 10^9 (infinity), as per the guidelines on how far a cow can go
    def move(self,ocow): # ocow is the other cow object to consider
        # if they're in the same spot, change nothing.
        if self.x == ocow.x and self.y == ocow.y:
            return
        # if they're facing the same direction and along the same line of movement, and if self is on the bottom or to the left,
        # then that's as far as it goes. self.u is then updated.
        if self.dir == ocow.dir:
            if self.x==ocow.x and self.y<ocow.y:
                self.u=min(self.u,self.y-ocow.y)
            elif self.y==ocow.y and self.x<ocow.x:
                self.u=min(self.u,self.x-ocow.x)
            return
        # the east has to be above and to the left of the north and vice versa. Edge cases are not covered here.
        # if ocow is not in the general correct spot, then stop
        if self.dir:
            if ocow.x not in range(self.x,self.x+self.u+1) or\
                self.y not in range(ocow.y,ocow.y+ocow.u):
                return
        else:
            if ocow.y not in range(self.y,self.y+self.u+1) or\
                self.x not in range(ocow.x,ocow.x+ocow.u):
                return
        # have to be facing different directions
        xd, yd = map(abs, (self.x-ocow.x, self.y-ocow.y))# x delta: difference between the two x coordinates, and y delta.
        dord=(xd,yd) if self.dir else (yd,xd)
        if dord[0]>dord[1]:
            self.u=min(self.u,dord[0])

cows=[]
for i in range(int(input())):
    z=input().split()
    z[1:]=list(map(int,z[1:]))
    cows.append(Cow(*z))
global inf
inf=[]
print(len(inf))
for i in cows:
    i.u = 1000000000
def extractTrueU(cow):
    # this is the other part to why the code works.
    # First, it is implied that there is at least one cow that goes to infinity, always. Against two cows, at least
    # one has to go to infinity relative to the other cow.
    # Second, this uses recursion to extract the true u of a cow, when compared against cows that we KNOW are also
    # true u. At least one is given: all the cows in inf. So, if it's in inf, it's a base case.

    if cow in inf:
        return
    retTo=[] # return to: cows that changed the current cow. We have to see if those cows have a true U.
    for i in cows:
        prevu=cow.u
        cow.move(i)
        if cow.u!=prevu:
            extractTrueU(i)
            retTo.append(i)
            cow.u=prevu
    for i in retTo:
        cow.move(i)
    if cow.u==1000000000:
        inf.append(cow)

for i in cows: extractTrueU(i)
# unnecessary for loop
# for i in cows:
#     for j in cows:
#         i.move(j)

for i in cows:
    print(i.u if i.u!=1000000000 else "Infinity")