# result is just n//5+n//25! Genius! Why didn't I think of that?? Oh wait I did, just not as efficiently as this one
c=0
n=int(input())
i=5
while n / i > 0:
    c += n//i
    i *= 5

print(c)