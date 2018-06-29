#include "bits/stdc++.h"
using namespace std;
const long long MOD = 998244353;
const int MAXN = 1e3 + 5;

int N;
long long A[MAXN];
long long dp[MAXN];//Number of good sequence ending at i.
long long cum[MAXN];//Total number of good sequences till i.
long long pas[MAXN][MAXN];

void comb()
{
	pas[0][0] = 1;
	pas[1][0] = 1;
	pas[1][1] = 1;
	for(int i = 2; i < MAXN; i++)
		pas[i][0] = 1;
	for(int i =1; i<MAXN; i++)
		for(int j = 1; j  < MAXN; j++)
			pas[i][j] = (pas[i - 1][j] + pas[i - 1][j - 1])%MOD;
}

int main()
{
	cin>>N;
	for(int i=1; i<=N; i++)
		cin>>A[i];
	comb();
	cum[1] = dp[1];
	for(int i = 2; i<=N; i++)
	{
		for(int j = i - 1; j >= 1; j--)
		{
			if((A[j] -1) >= 0 && (A[j]-1) < MAXN)
			dp[i] = ((dp[i]%MOD) + ((((cum[j - 1] + 1)%MOD)*pas[i - j - 1][A[j] - 1])%MOD))%MOD;
		}
		cum[i] = (cum[i - 1] + dp[i])%MOD;
	}
	cout<<cum[N]<<endl;
	return 0;
}