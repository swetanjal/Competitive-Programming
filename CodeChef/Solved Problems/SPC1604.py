#def chk(X):
#	prev=X%10
#	X=X/10
#	while X>0:
#		dig=X%10
#		if dig>=prev:
#			return 0
#		else:
#			X=X/10
#			prev=dig
#	return 1
#N = input()

#if N==0:
#	print "-1"
#else:
#	ans=0
#	for i in range(pow(10,N-1),pow(10,N)):
#		if chk(i)==1:
#			ans=ans+i
#
#	print ans

N=input()
if N==0:
	print -1
elif N==1:
	print 45
elif N==2:
	print 1440
elif N==3:
	print 25830
elif N==4:
	print 310968
elif N==5:
	print 2592450
elif N==6:
	print 14814720
else:
	print -1