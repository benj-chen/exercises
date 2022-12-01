"""
scores = []
def dfs(scores,graph, values, parent, current):
    if (parent in scores[current]):
        return scores[current][parent]
    if values[current]>=values[parent]:
        scores[current][parent]=0
        return 0
    res = 1
    for i in graph[current]:
        if i!=parent:
            res += dfs(scores,graph,values,current,i)
    scores[current][parent] = res

    return res
T = int(input())
for t in range(1,T+1):
    n = int(input())
    a = list(map(int,input().split()))
    a.append(2e9)
    # have this 2e9 so that for nodes that are starting out, their parent is this "null value"
    # this allows every member in the adjacency list to be hit
    scores = [{} for i in range(n)]
    graph = [[] for i in range(n)]
    for i in range(n-1):
        x, y = map(int,input().split())
        graph[x-1].append(y-1)
        graph[y-1].append(x-1)
    res = 0
    for i in range(n):
        res = max(res,dfs(scores,graph,a,n,i)) # n is the "null value"
    print("Case #{}: {}".format(t,res))

"""




scores = []
def dfs(scores,graph, values, parent, current):
    if (parent in scores[current]):
        return scores[current][parent]
    if values[current]>=values[parent]:
        scores[current][parent]=0
        return 0
    res = 1
    for i in graph[current]:
        if i!=parent:
            res += dfs(scores,graph,values,current,i)
    scores[current][parent] = res

    return res
T = int(input())
for t in range(1,T+1):
    n = int(input())
    values = list(map(int,input().split()))
    values.append(2e9)
    # have this 2e9 so that for nodes that are starting out, their parent is this "null value"
    # this allows every member in the adjacency list to be hit
    scores = [{} for i in range(n)]
    graph = [[] for i in range(n)]
    for i in range(n-1):
        x, y = map(int,input().split())
        graph[x-1].append(y-1)
        graph[y-1].append(x-1)

    res = 0
    for i in range(n):
        queue = [i]
        backqueue = [n]
        parent = n
        for current in queue+backqueue:
            # if (parent in scores[current]):
            if values[current]>=values[parent]:
                scores[current][parent]=0
            res = 1
            children = False
            for i in graph[current]:
                if i!=parent:
                    if current in graph[i]:
                        children=True   
                        # if the child hasn't figured out a score yet, put the children in, then recycle current
                        queue.append(i)
                    else:
                        res += scores[i][current]
            if children: queue.append(current)
            else: scores[current][parent]=res
            parent = current

        res = max(res,scores[i][n]) # n is the "null value"
    
    print("Case #{}: {}".format(t,res))
