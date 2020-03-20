S=raw_input()
ret=0
for char in S:
	if char=='a' or char=='e' or char=='i' or char=='o' or char=='u' or char=='1' or char=='3' or char=='5' or char=='7' or char=='9':
		ret+=1
print ret