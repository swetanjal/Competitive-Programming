#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;

int N, Q, u, k;

vector <int> edges[MAXN];
vector <int> pre;
int level[MAXN];
int idx[MAXN];
int start[MAXN];
int end[MAXN];
int timer = 0;

void dfs(int node, int parent)
{
	start[node] = timer;
	if(parent == -1)
		level[node] = 0;
	else
		level[node] = level[parent] + 1;
	pre.push_back(node);
	int L = edges[node].size();
	for(int i = 0; i < L; i++){
		if(edges[node][i] == parent)continue;
		++timer;
		dfs(edges[node][i], node);
	}
	end[node] = timer;
}

int parent[MAXN];

int main()
{
	cin>>N>>Q;
	for(int i = 2; i <= N; i++){
		int u, v;
		cin>>u;
		v = i;
		parent[i] = u;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i = 1; i <=N; i++)
		sort(edges[i].begin(), edges[i].end());
	dfs(1, -1);
	for(int i = 0; i < pre.size(); i++)
		idx[pre[i]] = i;
	while(Q--)
	{
		cin>>u>>k;
		int new_idx = idx[u] + k - 1;
		if(k == 1)
			cout<<u<<endl;
		else if(new_idx >= N)
			cout<<"-1\n";
		else if(start[pre[new_idx]] >= start[u] && end[pre[new_idx]] <= end[u])
			cout<<pre[new_idx]<<endl;
		else
			cout<<"-1\n";
		//cout<<dfs2(u, parent[u], k)<<endl;
	}
	return 0;
}