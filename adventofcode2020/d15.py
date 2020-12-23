with open('dec15input', 'r') as file:
    INPUTS = list(map(int, file.readlines()[0].split(',')))

def stinky_sol(n):
    # stinky_sol is the first version that I had of this problem. Although capable to solve part 1, it wasn't capable
    # to solve part 2, as I let it run for 20 hours before terminating the program. It still produces correct answers
    # in my experience, but I named this function stinky_sol because its runtime stinks.
    # return: the nth number in the sequence of the memory game.
    res = {INPUTS[x]: len(INPUTS) - x for x in range(len(INPUTS))}
    toConsider = INPUTS[-1]
    for x in range(n - len(INPUTS)):  # works

        if toConsider in res:  # short-circuit or prevents error
            temp = res[toConsider] - 1
        else:
            temp = 0
        res[toConsider] = 1
        toConsider = temp
        for y in res:
            res[y] += 1
    return toConsider
def solution(n):
    # solution is the final version that I had of this problem. Its speed prior to its predecessor is unprecedented.
    # I'm really proud of this one for how fast it ran!
    # return: the nth number in the sequence of the memory game.
    res = {INPUTS[x]: x for x in range(len(INPUTS))}
    toConsider = INPUTS[-1]
    for x in range(len(INPUTS)-1,n-1):
        temp=x-res[toConsider] if toConsider in res else 0
        res[toConsider] = x
        toConsider = temp
    return toConsider
# part 1 answer 763 using solution. Solving time: ~0.03 sec
print(solution(2020))
# part 1 answer 763 using stinky_sol. Solving time: ~0.07 sec
# print(stinky_sol(2020))

# part 2 answer 1876406 using solution. Solving time: ~9 seconds
print(solution(30000000))
# part 2 answer (1876406?) using stinky_sol. Solving time: unknown, at least 20 hours (before terminated)
# print(stinky_sol(30000000))

# further information, just because I was so excited about this day's solution. Units: seconds. Trials: sys+user time.
# "mean" refers to the mean of all of the trials, while "average" drops the fastest and slowest times (aka outliers),
# then evaluates the mean of what's left. This idea is what is used when observing a set of rubik's cube times,
# to prevent a very good or very bad scramble from ruining the average.
# Data:
# solution(1000000), with 5 trials
# mean: 0.185
# average (mean of the 3 middle trials): 0.184
# trial 1: 0.192
# trial 2: 0.181
# trial 3: 0.183
# trial 4: 0.183
# trial 5: 0.186

# solution(10000000), with 5 trials
# mean: 2.6500
# average: 2.6357
# trial 1: 2.679
# trial 2: 2.530
# trial 3: 2.813
# trial 4: 2.564
# trial 5: 2.664

# solution(100000000), with 5 trials
# mean: 33.107
# average: 33.022
# trial 1: 32.705
# trial 2: 33.764
# trial 3: 33.400
# trial 4: 32.880
# trial 5: 32.786

# solution(1000000000), with 5 trials
# mean: 674.1972
# average: 650.69
# trial 1: 613.362
# trial 2: 805.555
# trial 3: 618.989
# trial 4: 714.091
# trial 5: 618.989