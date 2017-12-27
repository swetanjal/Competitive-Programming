N=input()
while N>9:
	n=1
	while N>0:
		dig=N%10
		N=N/10
		if dig!=0:
			n=n*dig
	N=n;
print N