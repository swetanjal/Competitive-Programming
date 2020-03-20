#include <bits/stdc++.h>
using namespace std;
const int INF=100000;
int N,M;
int dp[1005][1005];
char A[1005],B[1005];
void print(int ind1, int ind2)
{
	if(ind1==N && ind2==M)return;
	if(ind1==N)
	{
		cout<<B[ind2];
		print(ind1,ind2+1);
	}
	else if(ind2==M)
	{
		cout<<A[ind1];
		print(ind1+1,ind2);
	}
	else if(A[ind1]==B[ind2])
	{
		cout<<A[ind1];
		print(ind1+1,ind2+1);
	}
	else
	{
		if(dp[ind1+1][ind2]==dp[ind1][ind2+1])
		{
			if(A[ind1]<=B[ind2])
			{
				cout<<A[ind1];
				print(ind1+1,ind2);
			}
			else
			{
				cout<<B[ind2];
				print(ind1,ind2+1);
			}
		}
		else if(dp[ind1+1][ind2]<dp[ind1][ind2+1])
		{
			cout<<A[ind1];
			print(ind1+1,ind2);
		}
		else
		{
			cout<<B[ind2];
			print(ind1,ind2+1);
		}
	}
}
int rec(int ind1, int ind2)
{
	if(ind1==N && ind2==M)return 0;
	if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
	if(ind1==N)dp[ind1][ind2]=1+rec(ind1,ind2+1);
	else if(ind2==M)dp[ind1][ind2]=1+rec(ind1+1,ind2);
	else if(A[ind1]==B[ind2])dp[ind1][ind2]=1+rec(ind1+1,ind2+1);
	else dp[ind1][ind2]=1+min(rec(ind1+1,ind2),rec(ind1,ind2+1));
	return dp[ind1][ind2];
}
int main()
{
	cin>>N>>M;
	for(int i=0; i<N; i++)cin>>A[i];
	for(int i=0; i<M; i++)cin>>B[i];
	for(int i=0; i<=N; i++)for(int j=0; j<=M; j++)dp[i][j]=-1;
	rec(0,0);
	print(0,0);
	return 0;
}
