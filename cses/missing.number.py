# https://cses.fi/problemset/task/1083
print(sum(range(int(input())+1))-sum(map(int,sorted(input().split()))))