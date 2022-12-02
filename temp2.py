# basic problem on codeforces etc
# list that is N long
# queries (~ request or like mini input) that ask
# what the sum of the list from indices I to J is
# in problems with queries, you may need to modify the input
# in the beginning for faster processing across all queries
# for this sample problem and for the palin problem we need to modify
# the input

# 5 3 2 1 4
# 1 2
    # 5
# 2 4
    # 7
# 1 3
    # 6

# easy way is O(N * Q): take each and go through and add up
# fast way is O(N + Q)
# prefix sums
ls = [5,3,2,1,4]
queries = [
    [1,3],
    [2,5],
    [1,4]
]

# process the input first
newls = [0]
for i in ls:
    newls.append(i+newls[-1])

print(newls)

for q in queries:
    print(newls[q[1]]-newls[q[0]])

# palin problem: have separate psums for each letter
