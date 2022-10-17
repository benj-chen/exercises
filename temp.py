T = int(input())+1
for t in range(1,T):
    n,q = map(int,input().split())
    tree = dict()
    for a in range(n-1):
        i,j = map(int,input().split())
        if i in tree:
            tree[i].append(j)
        else:
            tree[i] = [j]
        if j in tree:
            tree[j].append(i)
        else:
            tree[j] = [i]
    for i in range(q):
        input()

    ans = -1
    print("Case #{}: {}".format(t,ans))