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

# part 1
# from random import shuffle
# def rand5():
#     x=[]
#     for y in range(10):
#         x.append(1)
#         x.append(2)
#         x.append(3)
#         x.append(4)
#         x.append(5)
#     shuffle(x)
#
#     for y in x:
#         yield y
#
#
# def rand7():
#     #1 2 3 4 5, -2 -1 0 1 2
#
#     ss=next(rand5())/5*7
#
#     ress=[x/5*7 for x in range(1,8)]
#     print(res)
#     return ress.index(ss)+1

from random import randint
rand5=lambda: randint(1,5)
def rand7():
    return list(range(1,8))[int(rand5()/6*8)-1]


print('function start')

res=[]
for x in range(10000):
    res.append(rand7())
print('function end')
for x in range(1,8):
    print(res.count(x))
# """
#     scenarios
#     1 -2    -1
#     1 -1    0
#     1 0     1
#     1 1     2
#     1 2     3
#     2 -2    0
#     2 -1    1
#     2 0     2
#     2 1     3
#     2 2     4
#     3 -2    1
#     3 -1    2
#     3 0     3
#     3 1     4
#     3 2     5
#     4 -2    2
#     4 -1    3
#     4 0     4
#     4 1     5
#     4 2     6
#     5 -2    3
#     5 -1    4
#     5 0     5
#     5 1     6
#     5 2     7
#     """
