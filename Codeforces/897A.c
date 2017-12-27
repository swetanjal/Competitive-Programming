#include <stdio.h>

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	char S[N+5];
	scanf("%s",S);
	while(M--)
	{
		int l,r;
		char c1,c2;
		scanf("%d %d ",&l,&r);
		scanf("%c %c",&c1,&c2);
		int i;
		for(i=0; i<N; i++)
		{
			if(i>=(l-1) && i<=(r-1) && S[i]==c1)
				S[i]=c2;
		}
	}
	printf("%s\n", S);
	return 0;
}