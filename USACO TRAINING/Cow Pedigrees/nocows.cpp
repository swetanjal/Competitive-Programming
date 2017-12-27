/*
ID: swetanj2
LANG: C++
TASK: nocows
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD=9901;
int dp[105][205];
int N,K;
int main()
{
	ifstream cin("nocows.in");
	ofstream cout("nocows.out");
	cin>>N>>K;
	dp[0][1]=0;
	for(int i=1; i<=K; i++)
	dp[i][1]=1;
	for(int i=1; i<=K; i++)
	{
		for(int j=1; j<=N; j++)
		{
			for(int cnt=1; cnt<j; cnt++)
			dp[i][j]=(dp[i][j]+(dp[i-1][cnt]*dp[i-1][j-cnt-1]))%MOD;
		}
	}
	cout<<(dp[K][N]-dp[K-1][N]+MOD)%MOD<<endl;
}
