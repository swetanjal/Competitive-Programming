#include "bits/stdc++.h"
using namespace std;
const long long MOD = 1e9 + 7;
const int MAXNM = 1e3 + 5;
long long A[MAXNM];
long long dp[MAXNM][MAXNM];
int N,M,S;
int T;

long long rec(int ind, int passes)
{
	if(ind < 0 || ind >= N)return 0;
	if(passes == -1 && ind == S)return 1;
	if(passes == -1)return 0;
	if(dp[ind][passes]!=-1)return dp[ind][passes];

	return dp[ind][passes] = (rec(ind - A[passes], passes - 1) + rec(ind + A[passes], passes - 1))%MOD;
}

void solve()
{
	cin>>N>>M>>S;
	for(int i=0; i<M; i++)
		cin>>A[i];
	for(int i=0; i<MAXNM; i++)
		for(int j=0; j<MAXNM; j++)
			dp[i][j] = -1;
	S--;
	for(int i=0; i<N; i++)
		cout<<rec(i,M - 1)<<" ";
	cout<<endl;
	return;
}

int main()
{
	cin>>T;
	while(T--)
		solve();
	return 0;
}