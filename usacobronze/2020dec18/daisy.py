avgflower=int(input())
inputs=list(map(int,input().split()))

for cur in range(len(inputs)-1):
    for targ in range(cur+1,len(inputs)):
        targets=inputs[cur:targ+1]
        if sum(targets)/len(targets) in targets:
            avgflower+=1
print(avgflower)