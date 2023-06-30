year = 1900
month = 1
day = 7 # sunday
ct = 0
# dow = 0 # Sunday 0, Monday 1, ... Saturday 6
while year < 2001:
    # step
    day += 7
    # update dates
    if month in (1,3,5,7,8,10,12):
        if day > 31:
            month += 1
            day -= 31
    elif month in (4,6,9,11):
        if day > 30:
            month += 1
            day -= 30
    else:
        # february
        # is it a leap year
        if year % 4 == 0 and ((year % 400 == 0) == (year % 100 == 0)):
            if day > 29:
                month += 1
                day -= 29
        else:
            if day > 28:
                month += 1
                day -= 28
    
    if month > 12:
        month -= 12
        year += 1
    
    # is it a first day of the motnh
    if day == 1:
        if year < 1901: continue
        ct+=1

print(ct)
