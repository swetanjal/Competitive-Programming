T=input()
while T>0:
	S=raw_input()
	CNT=0
	L=len(S)
	for i in range(1,L):
		if (S[i]=='1' and S[i-1]=='0') or (S[i]=='0' and S[i-1]=='1'):
			CNT=CNT+1
	if L!=1:
		if (S[L-1]=='1' and S[0]=='0') or (S[L-1]=='0' and S[0]=='1'):
			CNT=CNT+1
	if CNT<=2:
		print "uniform"
	else:
		print "non-uniform"
	T=T-1