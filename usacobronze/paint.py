with open("paint.in","r") as fin:
    a,b,c,d = map(int,fin.read().split())
with open("paint.out","w") as fout:
    fout.write(str(max(b,d)-min(a,c) if (a<=c and b>=c or (c<=a and d>=a)) else b-a + d-c))