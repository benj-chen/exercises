# 10. Find the sum of all the primes below two million
import sympy
up=sympy.prime(2000000)
print("10. Find the sum of all the primes below two million:",sum(sympy.primerange(1,up)))

# 9. Find a Pythagorean triple a^2+b^2=c^2 such that a+b+c=1000
# a<b<c so a is under 1000/3=334, b is under 1000/2=500
found=False
for x in range(1,334):
    for y in range(x,501):
        z=1000-x-y
        if x**2+y**2==z**2:
            print("9. Find a Pythagorean triple a^2+b^2=c^2 such that a+b+c=1000:",x,y,z)
            found=True
            break
    if found: break

# 8. 13 adjacent digits to make the most digits is?
num="\
73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450"
num=num.split('0')
t=[]
for x in num:
    if len(x)>=13: t.append(x)
num=t[:]
del t
best=(0,0)
for x in num:
    for y in range(len(x)-13):
        cur=x[y:y+13]
        res=1
        for x in list(cur):
            res*=int(x)
        if res>int(best[0]): best=(cur,res)
print("8. 13 adjacent digits to make the most digits is?",best)

# 7. 10001st prime number?

primes=[2]
x=3
while True:
    isprime=True
    for y in primes:
        if x%y==0:
            isprime=False
            break
    if isprime: primes.append(x)
    x+=1
    if len(primes)==10001:break
print('7. 10001st prime number: ',primes[-1])


# 6. Difference between the sum of the squares of the first one hundred natural numbers and the square of the sum
def square(x): return x**2
num=list(range(1,101))
sum_squares=sum(list(map(square,num)))
square_sum=square(sum(num))
print("6. Difference between the sum of the squares of the first one hundred natural numbers and the square of the sum: ",square_sum-sum_squares)

# 5. Smallest number evenly divisible among 1-20
# it's actually 5,7,9,11,13,16,17,19 so
print('5. Smallest number evenly divisible among 1-20:',5*7*9*11*13*16*17*19)

# 4. Largest palindrome that is a product of two 3-digit numbers (work in prog)
"""
def isprime(n):
    assert n%2==1
    for x in range(3,n//2+1,2):
        if n%x==0: return False
    return True
def works(n):

    :param x: factor, probably 6 digits and close to 999999 that can be factored into two 3-digit numbers
    :return: bool

    factors=[]
    while bin(n)[-1]=='0':
        factors.append(2)
        n=n>>1
    print(n)
    while True:
        if isprime(n): return factors+[n]
        factors+=[x for x in range(2,n//2+1) if n%x==0]
        print(factors)


print(works(25))
"""
def getpal():
    pal=[]
    for x in range(999,100,-1):
        pal.append(str(x)+''.join(list(reversed(str(x)))))
    return list(map(int,pal))
pal=getpal()
print(pal)
# 3. Largest prime factor of the number 600851475143
def isprime(n):
    for x in range(2,n//2+1):
        if n%x==0: return False
    return True
n=600851475143
# print("3. Largest prime factor of the number 600851475143\n",[x for x in reversed(([x for x in range(2,n//2+1) if n%x==0])+[n]) if isprime(x)][0])
#^ Never uncomment that. The code takes a very very long time to run. However, I tested it on smaller n's, and it works as described

# 2. Sum up all of the even fib numbers under 4 000 000
var1=1
var2=2
fib=[]
while True:
    fib.append(var1)
    fib.append(var2)
    var1+=var2
    var2+=var1
    if var1>=4000000 or var2>=4000000: break
print("2. Sum up all of the even fib numbers under 4 000 000\n", sum(fib[x] for x in range(1,len(fib),3)))

# 1. Sum of all multiples of 3 and 5 below 1000
print("1. Sum of all multiples of 3 and 5 below 1000\n", sum(x for x in range(1,1000) if x%3==0 or x%5==0))