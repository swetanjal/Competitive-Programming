/*
ID: swetanj2
LANG: C++
TASK: concom
*/
#include <bits/stdc++.h>
using namespace std;
int N,u,v,p;
int val[1005][1005];
int dp[1005][1005];
vector <int> edges[1005];
int solve(int owner, int company)
{
	if(company==owner)return 0;
	if(dp[owner][company]!=-1)return dp[owner][company];
	int l=edges[owner].size();
	dp[owner][company]=val[owner][company];
	for(int i=0; i<l; i++)
	{
		if(solve(owner,edges[owner][i])>50)
		dp[owner][company]+=solve(edges[owner][i],company);
	}
	return dp[owner][company];
}
int main()
{
	ifstream cin("concom.in");
	ofstream cout("concom.out");
	cin>>N;
	for(int i=1; i<=N; i++)
	{
		cin>>u>>v>>p;
		edges[u].push_back(v);
		val[u][v]=p;
	}
	for(int i=0; i<=100; i++)for(int j=0; j<=100; j++)dp[i][j]=-1;
	for(int i=1; i<=100; i++){
		for(int j=1; j<=100; j++){
			if(i==j)continue;
			if(solve(i,j)>50)cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}
