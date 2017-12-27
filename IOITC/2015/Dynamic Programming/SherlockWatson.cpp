#include <bits/stdc++.h>
using namespace std;
int T,N;
int A[100005];
int dp[100005][2];
int rec(int ind, int prev)
{
	if(ind==N)return 0;
	if(dp[ind][prev]!=-1)return dp[ind][prev];
	if(prev==0)
	{
		dp[ind][prev]=max(A[ind]-1+rec(ind+1,1),rec(ind+1,0));
	}
	else 
	{
		dp[ind][prev]=max(abs(A[ind]-A[ind-1])+rec(ind+1,1),abs(A[ind-1]-1)+rec(ind+1,0));
	}
	return dp[ind][prev];
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0; i<N; i++)cin>>A[i];
		for(int i=0; i<N; i++)for(int j=0; j<=1; j++)dp[i][j]=-1;
		cout<<max(rec(1,0),rec(1,1))<<endl;
	}
	return 0;
}
