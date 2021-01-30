file=open("i1", "r")
# make sure to leave a blank newline at the bottom
res=[int(x[:-1]) for x in file.readlines()]
file.close()

for x in res:
    for y in res:
        if x+y==2020:
            answer=(x,y)


answer #this makes sure an answer actually exists
# Part 1 answer 388075
print(answer[0]*answer[1])

answer2=()
for x in res:
    for y in res:
        for z in res:
            if x+y+z==2020:
                answer2=(x,y,z)
answer2 #this makes sure an answer for part 2 exists
# Part 2 answer 2934505261
print(answer2[0]*answer2[1]*answer2[2])