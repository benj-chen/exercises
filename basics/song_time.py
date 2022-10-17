inp = "---"
times = []
done = True
while done:
    inp = input("press enter when done, otherwise enter a timestamp (hr:min:sec.ms or min:sec.ms or sec.ms or hr:min:sec, etc.) and press enter: ")
    done = False
    if inp=="":
        inp = input("Your desired time? ")
        done = True
    try:
        assert inp
        mult = 1
        num = 0
        if inp.count(".") not in (0,1):
            print("too many dots")
            raise ValueError
        inp = inp.split(':')
        print(inp)
        if '.' in inp[-1]:
            print(inp[-1][inp[-1].index('.'):])
            num += float(inp[-1][inp[-1].index('.'):])
            print(num)
            inp.append(inp.pop().split('.')[0])
        inp = list(map(int,inp))
        while len(inp):
            num += inp.pop() * mult
            mult*=60
        times.append(num)
    except ValueError:
        pass
    except AssertionError:
        print("try again")
    except:
        print("cannot have letters")
wanted_time = times.pop()
times.sort()
for i in range(len(times)):
    intervals = []
    for j in range(i+1,len(times)):
        # could binary search but whatever
        if times[j]-times[i] > wanted_time:
            dist1 = abs(intervals[-1]-wanted_time)
        intervals.append(times[j]-times[i])
        