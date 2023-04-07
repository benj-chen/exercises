def bs(ls,x,st,end):
    # add sentinels of 0 and infinity beforehand
    print(st,end)
    if (st +1 == end or end+1==st or st==end):
        # either st or st+1
        if ls[st] >= x: return st
        if ls[end] >= x: return end
        assert ls[max(st,end)+1] >= x
        return max(st,end)+1
    mid = (st+end)//2
    if ls[mid]==x: return mid
    if ls[mid]<x: return bs(ls,x,mid+1,end)
    if ls[mid]>x: return bs(ls,x,st,mid-1)
ls = [-1e9,1,2,3,5,6,7,1e9]
print(bs(ls,0,0,8))
print(bs(ls,4,0,8))
print(bs(ls,5,0,8))
print(bs(ls,9,0,8))
# 1 4 4 7
