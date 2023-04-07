t = int(input())
for T in range(t):
    n,k = map(int,input().split())
    s = input()
    # queries
    g, h  = [], []
    for i in range(n):
        if s[i]=='G':
            g.append([max(0,i-k),min(n-1,i+k)])
        else:
            h.append([max(0,i-k),min(n-1,i+k)])
    # for g and h respectively, find hottest spot that feeds the most cows
    cur_len = 1
    g_len = []
    g_indexes = []
    maybe_hot = 0 # index
    for i in range(1,len(g)): #this probably doesn't work
        if g[i][0] < g[maybe_hot][1]:
            cur_len+=1
        else:
            g_len.append(cur_len)
            g_indexes.append(maybe_hot)

    print(g_len)
    print(g_indexes)