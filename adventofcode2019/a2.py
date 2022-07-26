inp = input()
total = 0
while inp!="":
    num = int(inp)
    total -= num
    while num > 0:
        total += num
        num = num // 3 - 2
    inp = input()
print(total)