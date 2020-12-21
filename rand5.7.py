# Part 1:
#
# Implement a function called "rand7" that generates random numbers, uniformly from 1 to 7, without using any
# supporting libraries, except that you can pretend you have a function called "rand5", which generates random numbers
# uniformly from 1 to 5.
#
# Part 2:
#
# How many times do you call rand5 on average in order to provide one result for rand7?
#
# Find a way to do so that reduces the average number of calls to rand5.  In order to do this, you may (a) assume that
# rand7 will be called MANY times, and (b) store state if it helps you.
#
# Bonus: What is the theoretical limit?
# answer: If we are to assume that the numbers 1 through 5 are each called once per 5 numbers, then



from random import randint
rand5=lambda: randint(1,5)
def rand7():
    bytelist=''
    for x in range(3):
        while True:
            temp=rand5()
            if temp==3: continue
            byte=1 if temp>3 else 0
            bytelist+=str(byte)
            break
    return eval('0b'+bytelist)

print('function start')

res=[]
for x in range(400000):
    res.append(rand7())
print('function end')
for x in range(1,8):
    print(res.count(x))
