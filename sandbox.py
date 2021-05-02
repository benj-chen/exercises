t = int(input())
def factorial(n):
    res=n
    for i in range(1,n):
        res=res*i
    return res
print(factorial(3))
for test_case in range(t):
    print ("Case #"+str(test_case+1)+": ", end="")
    # get a,n,p
    a,n,p=input().split(" ")
    a=int(a)
    n=int(n)
    p=int(p)
    print((a**factorial(n))%p)
    # 5%3=2
    # 4%1 = 0