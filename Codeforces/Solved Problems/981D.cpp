#include "bits/stdc++.h"
using namespace std;
const int MAXN = 55;
int N, K, idx;
int dp[MAXN][MAXN];
long long cum[MAXN];
long long A[MAXN];
vector <int> p;
long long answer = 0;
int rec(int ind, int kk)
{
	if(kk == K && ind == (N + 1))return 1;
	if(kk>K || ind>N)return 0;
	if(dp[ind][kk]!=-1)return dp[ind][kk];
	dp[ind][kk] = 0;
	for(int i = ind; i<=N; i++)
	{
		long long lol = (1LL << idx);
		for(int j=0; j<p.size(); j++)
			lol = lol | (1LL << p[j]);
		long long s = (cum[i] - cum[ind-1]) & lol;
		if(s == (answer + (1LL << idx)))
		{	
			dp[ind][kk] = dp[ind][kk] | rec(i + 1, kk + 1);
		}
	}
	return dp[ind][kk];
}

int main()
{
	cin>>N>>K;
	for(int i=1; i<=N; i++)cin>>A[i];
	for(int i=1; i<=N; i++)cum[i] = cum[i-1] + A[i];
	for(int i=60; i>=0; i--)
	{
		idx = i;
		for(int j=0; j<MAXN; j++)
			for(int k=0; k<MAXN; k++)
				dp[j][k] = -1;
		if(rec(1,0)){
			p.push_back(i);
			answer = answer + (1LL<<i);
		}
	}
	cout<<answer<<endl;
	return 0;
}