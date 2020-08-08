# https://cses.fi/problemset/task/1622

# fast (uses recursion)
def ans(l):
    """

    :param l: list
    :return: all of the unique ways to permute the list items
    """
    if len(l)==1: #base case
        return l
    res=[]
    c=sorted(l[:])
    for x in l:
        del c[c.index(x)]
        t=ans(c)
        for y in t:
            res.append(x+y)
        c=sorted(l[:]) #add back the deleted item (restore for the next iteration)
    return res

e=set(ans(list(input())))
print(len(e))
for x in sorted(e):
    print(x)