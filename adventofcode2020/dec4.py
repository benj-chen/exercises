file = open("dec4input",'r')
inputs=file.readlines()
file.close()
inputs1=['']
c=0
for x in inputs:
    c+=1
    if x=="\n":
        inputs1.append('')
    else:
        inputs1[-1]+=x if "\n" not in x else x[:-1]+' '

validPassCount=0
for x in inputs1:
    if x.count(":")==8:
        validPassCount+=1

    if x.count(":")==7 and "cid" not in x:
        validPassCount+=1
# part 1 answer 216
print(validPassCount)

inputs=[]

for y in [x.split() for x in inputs1]:
    inputs.append(dict())
    for x in y:
        temp=x.split(":")
        if temp[0]=="cid": continue
        inputs[-1][temp[0]]=temp[1]
validcount=0

for x in inputs:
    if (len(x.keys()) != 7): continue
    marker1 = False
    marker2 = False
    for i in x['hcl'][1:]:
        if i not in "1234567890abcdef": marker1=True;break
    try: int(x['pid'])
    except: marker2 = True

    if \
    (x['byr']>'2002' or x['byr']<'1920') or \
    (x['iyr']<'2010' or x['iyr']>'2020') or \
    (x['eyr']<'2020' or x['eyr']>'2030') or \
    (x['ecl'] not in 'amb blu brn gry grn hzl oth'.split()) or \
    (len(x['pid']) != 9) or \
    ('cm' not in x['hgt'] and 'in' not in x['hgt']) or \
    ('cm' in x['hgt'] and (x['hgt']<'150cm' or x['hgt']>'193cm')) or \
    ("in" in x['hgt'] and (x['hgt']<'59in' or x['hgt']>"76in")) or \
    (x['hcl'][0]!="#" or len(x['hcl'])!=7) or \
    marker1 or marker2: continue
    validcount+=1
# part 2 answer 150
print(validcount)