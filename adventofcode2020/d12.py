file=open('dec12input','r')
ins=file.readlines()
file.close()

direction=1 # north is 0, east is 1, south is 2, west is 3. Will use modulus to simplify things
c=[0,0]
for x in ins:
    cmd=x[0]
    num=int(x[1:])

    if cmd=="F":
        cmd="NESW"[direction]
    if cmd in "SW":
        num=-num
    if cmd in "NS":
        c[1]+=num
    if cmd in "EW":
        c[0]+=num
    if cmd=="L":
        num=360-num # absolute degree change
    if cmd=="L" or cmd=="R":
        direction=(direction+num//90)%4
# part 1 answer 796
print(sum(map(abs,c)))
c=[0,0]
wp=[10,1] # east, north distance from ship
for x in ins:
    cmd=x[0]
    num=int(x[1:])

    if cmd=="F": #
        c[0]+=wp[0]*num
        c[1]+=wp[1]*num
    if cmd in "SW":
        num=-num
    if cmd in "NS": #
        wp[1]+=num
    if cmd in "EW":
        wp[0]+=num
    if cmd=="L":#
        num=360-num # absolute degree change
    if cmd=="L" or cmd=="R":#
        wp.reverse()
        if num==90:
            wp[1]=-wp[1]
        if num==180:
            wp[0],wp[1]=-wp[1],-wp[0]
        if num==270:
            wp[0]=-wp[0]

# part 2 answer 39446
print(sum(map(abs,c)))