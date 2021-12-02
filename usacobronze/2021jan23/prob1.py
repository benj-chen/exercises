abc=input()
w=input()
def lt(a,b):
    return abc.find(a)<abc.find(b)
ct=1
for x in range(len(w)-1):
    if not lt(w[x],w[x+1]):
        ct+=1
print(ct)