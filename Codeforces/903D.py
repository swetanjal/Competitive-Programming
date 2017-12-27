N=input()
H={}
S=[]
S=raw_input().split()
ans=0
cum=0
for i in range(1,N+1):
	tmp=long(S[i-1])
	if tmp in H:
		H[tmp]=H[tmp]+1
	else:
		H[tmp]=1
	cum+=tmp
	lol=(tmp*i)-cum
	less=tmp-1
	if less in H:
		lol=lol-((H[less]*tmp)-(H[less]*less))
	less=tmp+1
	if less in H:
		lol=lol-((H[less]*tmp)-(H[less]*less))
	ans=ans+lol

print ans