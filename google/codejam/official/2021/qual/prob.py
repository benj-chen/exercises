T=int(input())
for t in range(1,T+1):
    x,y,s=input().split()
    price={"CJ":x,"JC":y,"CC":0,"JJ":0}
    print("Case #" + str(t),end=": ")
    s=s.strip("?")
    empty=[]
    filled=[]
    total=0
    for i in range(len(s)):
        if s[i]=="?":
            empty+=[i]
        else:
            filled+=[i]
    # cover front
    # group

    for i in range(1,len(empty)-1):
        if empty[i-1]+1!=empty[i] and empty[i]+1!=empty[i+1]:
            # sep
            total+=price[s[empty[i]-1]+s[empty[i]+1]]
        else:
            total+=min(x,y)
    print(total)     
        


    
# J?C: JJC or JCC = both the same price
# J?J: JCJ or JJJ = choose J
# C?C: see J?J and reverse
# C?J: see J?C and reverse
# ??C: CCC
# C??C: CCCC
# J??C: any two of the same
# C???J: any three of the same
# if ? surrounded, choose X if CJ <JC else Y
# if more, choose any of the same
# edge:
# ?C: C
# ??C: C
# ??JC: J
# C?: C
# etc