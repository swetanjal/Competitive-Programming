N=input()
cnt=0
flag=1
last=-1
while N>0:
	dig=N%10
	if dig!=4 and dig!=1:
		flag=0
		break
	if dig==4:
		cnt=cnt+1
	else:
		cnt=0
	if cnt==3:
		flag=0
		break
	last=dig
	N=N/10
if flag==1 and last==1:
	print "YES"
else:
	print "NO"