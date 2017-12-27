#include <stdio.h>
long long x,y,p,q;
int T;
long long _max(long long a, long long b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld %lld %lld %lld",&x,&y,&p,&q);
		if((x*1.0/y)==(p*1.0/q))
		{
			printf("0\n");
			continue;
		}
		if(p==0)
		{
			if(x==0)
				printf("0\n");
			else printf("-1\n");
			continue;	
		}
		if(q==p)
		{
			printf("-1\n");
			continue;
		}
		long long x_prime=_max((x/p)+((x%p)==0?0:1),_max((y/q)+((y%q)==0?0:1),((y-x)/(q-p))+((y-x)%(q-p)==0?0:1)));
		long long ans=(q*x_prime)-y;
		printf("%lld\n", ans);
	}
	return 0;
}