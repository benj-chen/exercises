from functools import cache
@cache # to memoize
def solve(n, l):
    # n: number of total tiles
    # l: length of one tile. non zero.
    # returns number of ways to arrange (including possibly nothing at all)
    if n < l: return 1
    if n==l: return 2

    total = 1
    for i in range(n-l+1):

        # put a tile starting at this suffix: this config adds solve(n-i-l,l) choices
        total += (solve(n-i-l,l))
    return total
print(solve(50,2)-1 + solve(50,3)-1 + solve(50,4)-1) # at least one colored tile must be used
