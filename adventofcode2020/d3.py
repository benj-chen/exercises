file=open("i3", 'r')
inputs=[x[:-1] for x in file.readlines()]
file.close()

#the first index is the y value, the second index is the x value.
# evaluate r3d1 which is right 3, down 1
def f(r, d):
    count=0
    xinput=0
    yinput=0
    while yinput<=len(inputs)-1:
        # record pos
        try:
            pos=inputs[yinput][xinput]
        except:
            xinput-=len(inputs[0])
            pos=inputs[yinput][xinput]
        if pos=='#': count+=1
        xinput+=r
        yinput+=d
    return count
# Part 1 answer 257
print(f(3,1))
# Part 2 answer 1744787392
print(f(1,1)*f(3,1)*f(5,1)*f(7,1)*f(1,2))