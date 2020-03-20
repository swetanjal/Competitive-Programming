#include <bits/stdc++.h>
using namespace std;
int N,K,A[10005];
long long dp[10005][105];
long long rec(int ind, int cnt)
{
	if(cnt>K)return 0;
	if(ind==N)return 0;
	if(dp[ind][cnt]!=-1)return dp[ind][cnt];
	dp[ind][cnt]=max(A[ind]+rec(ind+1,cnt),rec(ind+1,cnt+1));
	return dp[ind][cnt];
}
int main()
{
	cin>>N>>K;
	for(int i=0; i<N; i++)cin>>A[i];
	for(int i=0; i<=N; i++)for(int j=0; j<=K; j++)dp[i][j]=-1;
	cout<<rec(0,0)<<endl;
	return 0;
}
