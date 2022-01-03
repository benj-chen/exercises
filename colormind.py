def get_nums(i):
    # get numbers in a string i and return as list
    res = []
    curnum = 0
    for j in i:
        if (curnum==0 and j=='0'):
            res.append(0)
            continue
        if j in "1234567890":
            curnum*=10
            curnum+=int(j)
        else:
            if curnum:
                res.append(curnum)
                curnum=0
    if curnum:
        res.append(int(curnum))
    return res


from subprocess import Popen, PIPE
# run(["curl","colormind.io/api/","--data-binary","'{\"model\":\"default\"}'"])
times = 100
# stdout to a csv file
fout = open(input("file: "),"a")
proc = Popen("""curl 'http://colormind.io/api/' --data-binary '{"model":"default"}'; """*times, shell=True,stdout=PIPE)
for i in range(times):
    res = get_nums(proc.stdout.readline().decode('utf-8').strip())
    hexform = ""
    for j in res:
        fout.write(str(j))
        hexform+=hex(j)[2:].zfill(2)
        if len(hexform)==6:
            fout.write(",#"+hexform)
            hexform=""
        fout.write(",")
    fout.write("\n")
fout.close()
print(res)
print(list(map(hex,res)))