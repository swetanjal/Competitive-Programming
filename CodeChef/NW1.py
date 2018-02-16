T=input()
while T>0:
	inp=raw_input().split(" ")
	W=int(inp[0])
	S=str(inp[1])
	pos=-1
	if S=="mon":
		pos=0
	elif S=="tues":
		pos=1
	elif S=="wed":
		pos=2
	elif S=="thurs":
		pos=3
	elif S=="fri":
		pos=4
	elif S=="sat":
		pos=5
	else:
		pos=6
	A=[]
	for i in range(0,7):
		A.append(0)
	for i in range(1,W+1):
		xxx=(pos+i-1)%7
		A[xxx]=A[xxx]+1
	ret=""
	for x in A:
		ret=ret+str(x)+" "
	print ret
	T=T-1