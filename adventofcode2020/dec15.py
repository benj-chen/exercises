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