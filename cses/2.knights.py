n=int(input())
if n==1:print(0);exit()
print('0\n6')
for x in range(3,n+1):
    print(int((x**2-1)*((x**2)/2)-4*(x-2)*(x-1)))