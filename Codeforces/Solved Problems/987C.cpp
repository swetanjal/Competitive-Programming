#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3001;
const long long inf = 1e14;
long long S[MAXN];
long long C[MAXN];
long long dp[MAXN][MAXN][3];
int N;
long long rec(int ind, int last, int cnt)
{
	if(cnt == 3)
		return 0;
	if(ind == (N+1))
	{
		if(cnt == 3)
			return 0;
		else
			return inf;
	}
	if(dp[ind][last][cnt] != -1)
		return dp[ind][last][cnt];

	dp[ind][last][cnt] = rec(ind + 1, last, cnt);
	if(S[last] < S[ind])
		dp[ind][last][cnt] = min(dp[ind][last][cnt], C[ind]*1LL + rec(ind + 1, ind, cnt + 1));
	return dp[ind][last][cnt];
}

int main()
{
	cin>>N;
	for(int i=1; i<=N; i++)
		cin>>S[i];
	for(int i=1; i<=N; i++)
		cin>>C[i];
	for(int i=0; i<MAXN; i++)
		for(int j=0; j<MAXN; j++)
			for(int k=0; k<3; k++)
				dp[i][j][k] = -1;
	long long ret = rec(1, 0, 0);
	if(ret == inf)cout<<"-1\n";
	else cout<<ret<<endl;
	return 0;
}