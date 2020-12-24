file=open('i6', 'r')
a=['']
for x in file.readlines():
    if x=='\n':
        a.append('')
    else:
        a[-1]+=x
file.close()
count=0
for x in a:
    count+=len(set(x))-1
# part 1 answer 6259
print(count)

count=0
for x in a:
    numpeople=x.count('\n')
    for y in set(x):
        if y=='\n': continue
        if x.count(y)==numpeople:
            count+=1
# part 2 answer 3178
print(count)