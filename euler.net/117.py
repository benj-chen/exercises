from functools import cache
@cache
def solve2(n):
    if n < 2: return 1
    total = 1
    for i in range(n):
        # at this position, try placing each type of tile
        for j in range(2,5):
            if i+j <= n:
                total += solve2(n-i-j)
    
    return total
print(solve2(50))
