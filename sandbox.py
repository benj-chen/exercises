tree = [
    [1,2],
    [],
    [3,4],
    [5],
    [],
    []
]
"""
        0
          \\
       2    1
    / /
    3 4
    |
    5
"""
global result
result = []
def dfs(starting_node):
    global result
    result=result + tree[starting_node]
    for i in tree[starting_node]:
        dfs(i)
dfs(0)
print(result)