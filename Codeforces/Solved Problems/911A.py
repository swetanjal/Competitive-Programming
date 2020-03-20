N=input()
A=raw_input().split(" ")
MIN=10000000000
for x in A:
	n=int(x)
	if n<MIN:
		MIN=n
last=0
for x in A:
	n=int(x)
	if n==MIN:
		break
	last+=1
ANS=10000000000
for x in range(last+1,N):
	n=int(A[x])
	if n==MIN:
		ANS=min(ANS,x-last)
		last=x
print ANS