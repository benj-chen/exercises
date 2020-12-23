file=open("dec8input","r")
ins=[x.split()+[False] for x in file.readlines()] # False is in every line to see if the computer has visited it or not.
# If it has, then the computer knows that there's an infinite loop, and terminates it by breaking
file.close()
acc=0 # Some lines in the code add or subtract from the accumulator
cmd=0 # The index number of the current thing to be looked at
while True:
    if ins[cmd][2]:
        # part 1 answer 2034
        print(acc)
        break
    if ins[cmd][0]=="acc":
        acc+=eval(ins[cmd][1])
        ins[cmd][2]=True
    elif ins[cmd][0]=="jmp":
        ins[cmd][2]=True
        cmd+=eval(ins[cmd][1])-1
    else:
        ins[cmd][2] = True
    cmd+=1

for x in range(len(ins)):
    acc=0
    cmd=0

    if ins[x][0]=="jmp":
        ins[x][0]="nop"
    elif ins[x][0]=="nop":
        ins[x][0]="jmp"
    else: continue
    while True:
        if cmd == len(ins):
            #part 2 answer 672
            print(acc)
            break
        if ins[cmd][2]:
            break
        if ins[cmd][0] == "acc":
            acc += eval(ins[cmd][1])
            ins[cmd][2] = True
        elif ins[cmd][0] == "jmp":
            ins[cmd][2] = True
            cmd += eval(ins[cmd][1]) - 1
        else:
            ins[cmd][2] = True
        cmd += 1

    if ins[x][0]=="jmp":
        ins[x][0]="nop"
    elif ins[x][0]=="nop":
        ins[x][0]="jmp"
    for x in range(len(ins)):
        ins[x][2]=False