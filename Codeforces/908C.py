import math
inp=raw_input().split(" ")
N=int(inp[0])
R=int(inp[1])
x=raw_input().split(" ")
X=[]
for item in x:
	X.append(int(item))
Y=[]
Y.append(R)
for i in range(1,N):
	y_c=R
	for j in range(0,i):
		C=(Y[j]*Y[j])+((X[j]-X[i])*(X[j]-X[i]))-(2*R*2*R)
		#print C
		if ((2*Y[j])*(2*Y[j]))<(4*C):
			continue
		tmp=(2*Y[j])+math.sqrt(((2*Y[j])*(2*Y[j]))-(4*C))
		y_c=max(y_c,tmp/2)
	#print y_c
	Y.append(y_c)
ANS=""
for item in Y:
	ANS=ANS+str(item)+" "
print ANS