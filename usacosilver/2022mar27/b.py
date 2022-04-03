s = input()
t = input()
q = int(input())
for _ in range(q):
    query = input()
    ms = [a for a in s if a in query]
    mt = [a for a in t if a in query]
    print('Y' if (''.join(ms)==''.join(mt)) else 'N', end='')
print()

