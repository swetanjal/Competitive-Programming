#include <bits/stdc++.h>
using namespace std;
const int MAX_LOG=20;
int N;
vector <int> edges[1000005];
vector <int> level_list[1000005];
bool visited[1000005];
int dp[1000005][20];
int L[1000005];
int st[1000005],en[1000005]; int timer;
void dfs2(int node, int level)
{
	if(visited[node])return;
	visited[node]=true;
	st[node]=++timer;
	level_list[level].push_back(timer);
	int l=edges[node].size();
	for(int i=0; i<l; i++)
	{
		dfs2(edges[node][i],level+1);
	}
	en[node]=timer;
}
void dfs1(int node, int level)
{
	if(visited[node])return;
	visited[node]=true;
	L[node]=level;
	int l=edges[node].size();
	for(int i=0; i<l; i++)
	{
		dfs1(edges[node][i],level+1);
	}
}
void preprocess()
{
	for(int i=1; i<=N; i++)for(int j=1; 1 << j <20; j++)dp[i][j]=-1;
	for(int j=1; 1 << j <N; j++)
	{
		for(int i=1; i<=N; i++)
		{
			if(dp[i][j-1]!=-1)
			dp[i][j]=dp[dp[i][j-1]][j-1];
		}
	}
}
int lca(int p, int k)
{
	for(int i=MAX_LOG; i>=0; i--)
	{
		if((1 << i) <=k)
		{
			p=dp[p][i];
			k = k - (1 << i);
		}
	}
	return p;
}
int main()
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
	scanf("%d ",&dp[i][0]);
	preprocess();
	for(int i=1; i<=N; i++)
	{
		if(dp[i][0]!=0)
		{
			edges[i].push_back(dp[i][0]);
			edges[dp[i][0]].push_back(i);
		}
	}
	for(int i=1; i<=N; i++)visited[i]=false;
	for(int i=1; i<=N; i++)
	{
		if(dp[i][0]!=0)continue;
		dfs1(i,1);
	}
	timer=0;
	for(int i=1; i<=N; i++)visited[i]=false;
	for(int i=1; i<=N; i++)
	{
		if(dp[i][0]==0)
		{
			dfs2(i,1);
		}
	}
	for(int i=1; i<=N; i++)
	{
		if(level_list[i].size()>0)
		sort(level_list[i].begin(), level_list[i].end());
	}
	int Q;
	cin>>Q;
	while(Q--)
	{
		int v,p;
		scanf("%d %d",&v,&p);
		int anc=lca(v,p);
		int l=st[anc], r=en[anc];
		int ans;
		int i=L[v];
		if(anc<=0)
		{
			ans=0;
			printf("%d\n",ans);
			continue;
		}
		ans= upper_bound(level_list[i].begin(), level_list[i].end(),r) - lower_bound(level_list[i].begin(), level_list[i].end(),l);
		ans=ans-1;
		if(ans==-1)
		{
			ans=0;
			printf("%d\n",ans);
		}
		else 
		printf("%d\n",ans);
	}
	return 0;
}
