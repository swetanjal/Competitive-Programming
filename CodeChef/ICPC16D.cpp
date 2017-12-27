#include <bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;
int N,tmp,T;
int exists[1000005];
long long dp[1000005];
vector <int> factors[750005];
void sieve()
{
	for(int i=1; i<=750000; i++)
		for(int j=i+i; j<=750000; j+=i)factors[j].push_back(i);
}
void solve()
{
	scanf("%d",&N);
	int i,j;
	for(i=0; i<=750000; i++){
		exists[i]=0;
	}
	for(i=1; i<=N; i++)
	{
		scanf("%d",&tmp);
		exists[tmp]=1;
	}
	int start=-1;
	for(i=1; i<=750000; i++){
		if(exists[i])
		{
			dp[i]=1;
			start=i+1;
			break;
		}
	}
	long long ANS=dp[start-1];
	for(i=start; i<=750000; i++){
		if(exists[i]==0)continue;
		dp[i]=1;
		for(j=0; j<(factors[i].size()); j++)
		{
			if(exists[factors[i][j]])
			dp[i]=(dp[factors[i][j]]+dp[i])%MOD;
		}
		ANS=(ANS+dp[i])%MOD;
	}
	printf("%lld\n", ANS);
}
int main()
{
	sieve();
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}