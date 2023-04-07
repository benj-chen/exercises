n,t = map(int,input().split())
pairs = []
for i in range(n):
    pairs.append(tuple(map(int,input().split())))

inventory = 0
result = pairs[0][0]
final_time = t
for i in range(n-1):
    print(pairs[i])
    # note next delivery time
    if pairs[i][0] > t: break
    if pairs[i+1][0] > t:
        pairs[i+1] = (t,-1)
        final_time = pairs[i][0]
    next_date = pairs[i+1][0]
    inventory += pairs[i][1]
    # calculate expected time to start starving
    exp = pairs[i][0] + inventory # plus 1??
    if exp <= next_date: # <=??
        # this is the date starving starts
        result += next_date - exp
        inventory = 0
        print("would starve")
    else:
        # shipment before starving starts
        inventory -= (next_date - pairs[i][0])
        print("would not starve")
    print(inventory)
    print()

# special case for the very end
print(result)

