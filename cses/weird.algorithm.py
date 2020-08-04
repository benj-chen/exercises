#create an algorithm that takes in a positive integer n. If even, divide by 2, if odd, multiply by 3 and add 1

n=input()
while n!=1:
    n=int(n)
    print(n, end=' ')
    if n%2==0:
        n>>=1
        continue
    n=n*3+1
print(1)