#include <stdio.h>

int main()
{
	int N;
	scanf("%d",&N);
	int A[N],B[N];
	int i;
	for(i=0; i<N; i++)
		scanf("%d %d",&A[i], &B[i]);
	int rated=0;
	for(i=0; i<N; i++)
	{
		if(A[i]!=B[i]){
			rated=1;
			break;
		}
	}
	if(rated)
		printf("rated\n");
	else
	{
		int sorted=1;
		for(i=1; i<N; i++)
		{
			if(A[i-1]<A[i]){
				sorted=0;
				break;
			}
		}
		if(sorted)printf("maybe\n" );
		else printf("unrated\n");
	}
	return 0;
}