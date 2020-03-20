#include <bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;
int N,P[200005]; long long sz[200005];
vector <int> edges[200005];
long long dp1[200005],dp2[200005],dp[200005];
void dfs3(int node)
{
	int L=edges[node].size();
	for(int i=0; i<L; i++)
	{
		dp[node]=(dp[node]+dp2[edges[node][i]])%MOD;
	}
	for(int i=0; i<L; i++)
	{
		dfs3(edges[node][i]);
	}
}
void dfs2(int node)
{
	int L=edges[node].size();
	dp2[node]=0;
	long long sum=0;
	for(int i=0; i<L; i++)sum=(sum+dp1[edges[node][i]])%MOD;
	for(int i=0; i<L; i++)
	{
		for(int j=i+1; j<L; j++)
		{
			dp2[node]=(dp2[node]+(((sz[edges[node][i]]*sz[edges[node][j]])%MOD)*(sum-dp1[edges[node][i]]-dp1[edges[node][j]])))%MOD;
		}
	}
	for(int i=0; i<L; i++)
	{
		dfs2(edges[node][i]);
		dp2[node]=(dp2[node]+(dp2[edges[node][i]]))%MOD;
	}
}
void dfs1(int node)
{
	int L=edges[node].size();
	dp1[node]=0;
	for(int i=0; i<L; i++)
	{
		for(int j=i+1; j<L; j++)
		{
			dp1[node]=(dp1[node]+(sz[edges[node][i]]*sz[edges[node][j]]))%MOD;
		}
	}
	for(int i=0; i<L; i++)
	{
		dfs1(edges[node][i]);
		dp1[node]=(dp1[node]+dp1[edges[node][i]])%MOD;
	}
}
int dfs(int node)
{
	int L=edges[node].size();
	sz[node]=1;
	for(int i=0; i<L; i++)
	sz[node]+=dfs(edges[node][i]);
	return sz[node];
}
int main()
{
	cin>>N;
	for(int i=1; i<=N; i++)
	{
		cin>>P[i];
		edges[P[i]].push_back(i);
	}
	dfs(0);
	dfs1(0);
	dfs2(0);
	dfs3(0);
	long long ans=0;
	for(int i=0; i<=N; i++)
	{
		ans=(ans+dp[i])%MOD;
	}
	cout<<ans<<endl;
}
/*
8
0 1 2 1 1 1 6 6
*/
