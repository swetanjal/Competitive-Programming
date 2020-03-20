#include <bits/stdc++.h>
using namespace std;
int N,sum=0;
int A[5005],dp[5005][5005];
int rec(int ind, int last)
{
	if(ind==N)return 0;
	if(dp[ind][last]!=-1)return dp[ind][last];
	if(A[ind]>=last)
	{
		dp[ind][last]=max(rec(ind+1,last),A[ind]+rec(ind+1,A[ind]));
	}
	else
	{
		dp[ind][last]=rec(ind+1,last);
	}
	return dp[ind][last];
}
int main()
{
	cin>>N;
	for(int i=0; i<N; i++)
	{
		cin>>A[i];
		sum+=A[i];
	}
	for(int i=0; i<=N; i++)for(int j=0; j<=5000; j++)dp[i][j]=-1;
	int LIS=rec(0,0);
	cout<<(sum-LIS)<<endl;
	return 0;
}
