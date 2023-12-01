# quick handy binary search, no trouble. cpp: use lower_bound
def binary_search(x): #counts number of #s <x, or min index i st a[i] >= x
    lo = 0
    hi = N
    while(hi > lo):
        mid = (hi + lo) // 2
        if (arr[mid] >= x):
            hi = mid
        else:
            lo = mid + 1
    return lo
