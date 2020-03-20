#include <bits/stdc++.h>
using namespace std;
int N,M,Q,u,v;
const long long neg=-1000000000000000;
int A[505][505];
long long dp[505][505];
vector <int> factors[505];
inline void factorise()
{
	for(int i=1; i<=500; i++)
	{
		factors[0].push_back(i);
	}
	for(int i=1; i<=500; i++)
	{
		int limit=(int)sqrt(i)+1;
		for(int j=1; j<=limit; j++)
		{
			if((i%j)==0)
			{
				int tmp=i/j;
				factors[i].push_back(j);
				if(tmp!=j)factors[i].push_back(tmp);
			}
		}
	}
}
inline long long rec(int X , int Y)
{
	if(X==0 && Y==0)return A[0][0];
	if(X<0 || Y<0 || X==N || Y==M)return neg;
	if(dp[X][Y]!=LONG_LONG_MIN)return dp[X][Y];
	int div=max(X,Y);
	int l=factors[div].size();
	for(int i=0; i<l; i++)
	{
		if((X%factors[div][i])==(Y%factors[div][i]))
		{
			dp[X][Y]=max(dp[X][Y],A[X][Y]+rec(X-factors[div][i],Y));
			dp[X][Y]=max(dp[X][Y],A[X][Y]+rec(X,Y-factors[div][i]));
			dp[X][Y]=max(dp[X][Y],A[X][Y]+rec(X-factors[div][i],Y-factors[div][i]));
		}
	}
	return dp[X][Y];
}
int main()
{
	scanf("%d %d %d", &N , &M, &Q);
	factorise();
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)scanf("%d",&A[i][j]);
	}
	for(int i=0; i<N; i++)for(int j=0; j<M; j++)dp[i][j]=LONG_LONG_MIN;
	while(Q--)
	{
		scanf("%d %d", &u , &v);
		printf("%lld\n",rec(u,v));
	}
	return 0;
}
