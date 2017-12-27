#include <stdio.h>
long long power(int a, int b)
{
	long long prod=1;
	int i;
	for(i=1; i<=b; i++)prod*=a;
	return prod;
}
int main()
{
	int K,i,j,k,l,m,n;
	long long P; long long ANS=0; int c=0;
	scanf("%d %lld",&K,&P);
	for(i=0; i<=9; i++)
	{
		for(j=0; j<=9; j++)
		{
			for(k=0; k<=9; k++)
			{
				for(l=0; l<=9; l++)
				{
					for(m=0; m<=9; m++)
					{
						for(n=0; n<=9; n++)
						{
							long long lol=((i*100000)+(j*10000)+(k*1000)+(l*100)+(m*10)+n);
							if(lol==0)continue;
							int cnt=0;
							long long copy=lol; long long rnum=0;
							while(copy>0)
							{
								rnum=(rnum*10)+(copy%10);
								copy/=10;
								cnt++;
							}
							c++;
							lol=(lol*power(10,cnt))+rnum;
							//printf("%lld\n", lol);
							ANS=(ANS+lol)%P;
							if(c==K)break;
						}
						if(c==K)break;
					}
					if(c==K)break;
				}
				if(c==K)break;
			}
			if(c==K)break;
		}
		if(c==K)break;
	}
	printf("%lld\n", ANS);
	return 0;
}