file=open("dec1input", "r")
# make sure to leave a blank newline at the bottom
res=[int(x[:-1]) for x in file.readlines()]
file.close()
# part 1
for x in res:
    for y in res:
        if x+y==2020:
            answer=(x,y)

# Part 1 answer 388075: print(answer[0]*answer[1])

# part 2
answer=()
for x in res:
    for y in res:
        for z in res:
            if x+y+z==2020:
                answer=(x,y,z)

# Part 1 answer 293450526: print(answer[0]*answer[1]*answer[2])