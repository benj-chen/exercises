inputs=list(map(int,input().split(' ')))
inputs.sort()
allsum=inputs[-1]
num1,num2=inputs[:2]
num3=allsum-num1-num2
print(num1, num2, num3)