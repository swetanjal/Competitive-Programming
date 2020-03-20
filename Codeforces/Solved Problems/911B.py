A=raw_input().split(" ")
N=int(A[0])
a=int(A[1])
b=int(A[2])
ANS=0
for i in range(1,N):
	x=a/i
	y=b/(N-i)
	if x==0 or y==0:
		continue
	ANS=max(ANS,min(x,y))
print ANS