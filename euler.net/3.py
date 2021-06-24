n = 600851475143
max_fac = 1

while (n!=1):
    for i in range(2,n+1):
        # find a number to divide by n
        if (n%i==0):
            n//=i
            max_fac=max(max_fac,i)
            break
print(max_fac)