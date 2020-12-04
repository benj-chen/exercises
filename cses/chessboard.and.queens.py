"""
https://cses.fi/problemset/task/1624
Example input:
........
........
..*.....
........
........
.....**.
...*....
........

Example output:
65
"""
arr=[input(),input(),input(),input(),input(),input(),input(),input()]
#No queen can be in the same column, row
a=arr[:]
for y in range(8):
    a+=[''.join([x[y] for x in arr])]
print(a)
if "********" in a:
    print(0);exit()
#use recursion for each open space.
def recursion():
    z=0
    global z
    if len(arr)==1:


#remove diagonal situations