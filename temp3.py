T = int(input())
for t in range(1,T+1):
    n, q = map(int,input().split())
    s = input() # len(s) = n
    psums = {l:[0] for l in "QWERTYUIOPASDFGHJKLZXCVBNM"}
    
    for i in s:
        for j in psums: # this is fine; j < 26
            psums[j].append(psums[j][-1] + (j==i))
    total = 0
    for i in range(q):
        l, r = map(int,input().split()) # 1-based counting
        counts = []
        for j in psums:
            counts.append(psums[j][r]-psums[j][l-1])
        num_good = sum(map(lambda x: x%2, counts))
        if num_good < 2: total += 1

    print("Case #{}: {}".format(t,total))

# ABAACCA
# ^ A:1 B:0 C:0
#  ^A:1 B:1 C:0
#   ^A:2 B:1 C:0
#    ^A:3B:1 C:0
#     ^ A:3 B:1 C:1
#      ^A:3 B:1 C:2
#       ^ A:4 B:1 C:2
def binary(ls, element, front, back):
    if front+1==back: return front
    mid = front + (back-front)//2
    if ls[mid]>element: return binary(ls,element,front,mid)
    else: return binary(ls,element,mid,back)