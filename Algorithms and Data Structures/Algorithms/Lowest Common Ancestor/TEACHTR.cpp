/* https://www.codechef.com/problems/TEACHTR */
#include "bits/stdc++.h"
using namespace std;
const int MAXLOG = 21; 
const int MAXN = 1e5+5;
int N,Q,u,v;
vector <int> edges[MAXN];
int parent[MAXN];
int level[MAXN];
int ancestor[MAXN][MAXLOG];


void dfs(int node, int p, int lev)
{
	level[node] = lev;
	parent[node] = p;
	int L=edges[node].size();
	for(int i=0; i<L; i++){
		if(edges[node][i]==p)continue;
		dfs(edges[node][i], node, lev+1);
	}
}

int lca(int a, int b)
{
	//Assuming level of a is lesser than b
	//Get b up...
	if(level[a]>=level[b])swap(a,b);
	for(int i=MAXLOG-1; i>=0; i--)
	{
		if(level[a]<=(level[b]-(1<<i)))
			b = ancestor[b][i];
	}
	if(a==b)return a;
	for(int i=MAXLOG-1; i>=0; i--)
	{
		if(ancestor[a][i]!=-1 && ancestor[b][i]!=-1 && ancestor[a][i]!=ancestor[b][i])
			a = ancestor[a][i], b=ancestor[b][i];
	}
	return parent[a];
}

int main()
{
	cin>>N;
	for(int i=1; i<N; i++){
		cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1,-1, 0);

	//preprocess
	for(int i=0; i<MAXLOG; i++)
		for(int j=1; j<=N; j++)ancestor[j][i] = -1;
	for(int i=1; i<=N; i++)ancestor[i][0] = parent[i];
	for(int i=1; i<MAXLOG; i++)
	{
		for(int j=1; j<=N; j++)
		{
			if(ancestor[j][i-1]!=-1)
				ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];
		}
	}
	//
	cin>>Q;
	while(Q--)
	{
		cin>>u>>v;
		int LCA = lca(u,v);
		if(LCA == u)cout<<u<<" taught "<<v<<endl;
		else if(LCA == v)cout<<v<<" taught "<<u<<endl;
		else cout<<"No idea\n";
	}
	return 0;
}