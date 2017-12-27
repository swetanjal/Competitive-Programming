/*
USACO 2011 December Problem 3(Silver Division)
Type: dp
*/
#include <bits/stdc++.h>
using namespace std;
int N,M; long long C[100005]; int A[5005]; int X[5005];
long long cum_min[100005]; long long dp[5005];
int main()
{
	//ifstream cin("I.10");
	cin>>N>>M;
	for(int i=0; i<N; i++)cin>>A[i];
	sort(A,A+N);
	for(int i=1; i<=N; i++)X[i]=A[i-1];
	for(int i=1; i<=M; i++)cin>>C[i];
	cum_min[M]=C[M];
	for(int i=M-1; i>=1; i--)cum_min[i]=min(cum_min[i+1],C[i]);
	dp[0]=0;
	for(int i=1; i<=N; i++)
	{
		dp[i]=LONG_LONG_MAX;
		for(int j=1; j<=i; j++)
		{
			dp[i]=min(dp[i],cum_min[X[i]-X[j]+1]+dp[j-1]);
		}	
	}
	cout<<dp[N]<<endl;
	return 0;
}
