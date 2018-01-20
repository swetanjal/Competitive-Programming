#include "stdio.h"

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int N;
		long long L,R;
		scanf("%d %lld %lld", &N, &L, &R);
		long long W[N];
		long long B[N];
		int E[N];
		int O[N];
		int i;
		for(i=0; i<N; i++)
		{
			scanf("%lld %lld", &W[i], &B[i]);
			E[i]=((W[i]*2)+B[i])%2;
			O[i]=((W[i]*1)+B[i])%2;
		}
		
		int even=0; int odd=0; int flag=0;
		for(i=0; i<N; i++)
		{
			if(flag==0)
				flag=E[i];
			else
				flag=O[i];
		}
		if(flag==0)even=1;
		flag=1;
		for(i=0; i<N; i++)
		{
			if(flag==0)
				flag=E[i];
			else
				flag=O[i];	
		}
		if(flag==0)
			odd=1;
		//printf("%d %d\n", odd,even);
		long long ans=0;
		if(even && odd)
		{
			ans=ans+(R-L+1);
		}
		else if(even)
		{
			long long Even=(R-L)/2;
			if(((L%2)==0) || ((R%2)==0))
				Even++;
			ans=Even;
		}
		else if(odd)
		{
			long long Odd=(R-L)/2;
			if(((L%2)==1) || ((R%2)==1))
				Odd++;
			ans=Odd;
		}
		else
		{
			ans=0;
		}
		printf("%lld %lld\n", ans, (R-L+1)-ans);
	}
}