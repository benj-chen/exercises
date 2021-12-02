# code uses walrus operator - see README if code doesn't run properly
with open('i22','r') as fin:inputs=fin.readlines()
# assume the card deck is valid
ch=inputs.index("\n")
if ch==-1 or "Player 1:\n" not in inputs or "Player 2:\n" not in inputs: raise AttributeError("wrong file, or file not formatted correctly, or missing crucial parts")
a,b=list(map(int,inputs[1:ch])),list(map(int,inputs[ch+2:]))
while a and b:
    i,j=a.pop(0),b.pop(0)
    (win:=a if i>j else b).extend(sorted((i,j),reverse=True))
win.reverse()
# part 1 answer 31269
print(sum((x+1)*win[x] for x in range(len(win))))

# reset a and b
a,b=list(map(int,inputs[1:ch])),list(map(int,inputs[ch+2:]))

# the new rules in layman's terms
# 1. if a card configuration appeared in a previous round of the current recursive level, player 1 wins.
# 2. If both players' current card value is <= the number of the remaining cards, then a new game occurs. THe original game
# remains untouched though.
# 3. otherwise, the winner is as normal.
# 4. When going into a new game of recursive combat, only copy the next n cards, where n is the card number drawn for each player.
def recc(a,b): # "recursive combat"
    configs=set()
    while a and b:
        if (iter := tuple(a + [-1] + b)) in configs: return a
        configs.add(iter)
        i, j = a.pop(0), b.pop(0)
        if i <= len(a) and j <= len(b):
            if recc(a[:i], b[:j])[0]: a+=[i, j]
            else: b+=[j, i]
        else:(a if i > j else b).extend(sorted((i, j), reverse=True))
    return [a] if a else (False, b)

win=list(reversed(recc(a,b)[-1]))

# part 2 answer 31151
print(sum((x+1)*win[x] for x in range(len(win))))