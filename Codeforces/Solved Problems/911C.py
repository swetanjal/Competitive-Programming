A=raw_input().split(" ")
X=int(A[0])
Y=int(A[1])
Z=int(A[2])
if X==1 or Y==1 or Z==1:
	print "YES"
elif (X==2 and Y==2) or (X==2 and Z==2) or (Y==2 and Z==2):
	print "YES"
elif X==3 and  Y==3 and Z==3:
	print "YES"
elif (X==2 and Y==4 and Z==4) or (X==4 and Y==2 and Z==4) or (X==4 and Y==4 and Z==2):
	print "YES"
else:
	print "NO"