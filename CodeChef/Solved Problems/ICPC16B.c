#include <stdio.h>
long long _abs(long long val)
{
	if(val>=0)return val;
	return -val;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		int N,i;
		scanf("%d",&N);
		long long A[N];
		for(i=0; i<N; i++)scanf("%lld",&A[i]);
		int non_zero_one=0;
		int plus=0; int minus=0;
		long long str=-1;
		for(i=0; i<N; i++)
		{
			if(_abs(A[i])!=0 && _abs(A[i])!=1){
				non_zero_one++;
				str=A[i];
			}
			if(A[i]==-1)minus++;
			else if(A[i]==1)plus++;
		}
		if(non_zero_one>1)
		{
			printf("no\n");
		}
		else if(non_zero_one==0)
		{
			if(minus>1 && plus==0)
			{
				printf("no\n");
			}
			else if(minus<=1 && plus==0)
			{
				printf("yes\n");	
			}
			else if(minus!=0 && plus!=0)
			{
				printf("yes\n");
			}
			else
			{
				printf("yes\n");
			}
		}
		else
		{
			if(str<0 && minus==0)
			{
				printf("yes\n");
			}
			else if(str>0 && minus==0)
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
		}
	}
	return 0;
}