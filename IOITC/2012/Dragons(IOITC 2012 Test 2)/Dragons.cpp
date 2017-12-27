#include <bits/stdc++.h>
using namespace std;
long long R,C;
int K,D;
struct element{
	long long x;
	long long y;
};
element A[305];
long long dp[305][305];
bool compare(element a, element b)
{
	return a.x<b.x;
}
long long dist(int i, int j)
{
	return (abs(A[i].x-A[j].x)+abs(A[j].y-A[i].y));
}
int main()
{
	cin>>R>>C>>K>>D;
	for(int i=0; i<D; i++)cin>>A[i].x>>A[i].y;
	sort(A,A+D,compare);
	for(int i=0; i<305; i++)
	for(int j=0; j<305; j++)dp[i][j]=1000000000000000005;
	for(int i=0; i<D; i++)
	{
		dp[i][1]=A[i].x+A[i].y;
	}
	for(int k=2; k<=K; k++)
	{
		for(int i=k-1; i<D; i++)
		{
			long long tmp=LONG_LONG_MAX;
			for(int j=0; j<i; j++)
			{
				tmp=min(tmp,dist(i,j)+dp[j][k-1]);
			}
			dp[i][k]=tmp;
		}
	}
	long long ans=LONG_LONG_MAX;
	for(int i=0; i<D; i++)ans=min(ans,dp[i][K]);
	cout<<ans<<endl;
	return 0;
}
