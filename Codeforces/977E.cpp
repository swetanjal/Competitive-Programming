#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 5;

int N,M,u,v;
vector <int> edges[MAXN];
int comp[MAXN];
int done[MAXN];
int visited[MAXN];
int component;

void dfs(int node)
{
	if(comp[node]!=-1)return;
	int L = edges[node].size();
	comp[node] = component; 
	for(int i=0; i<L; i++){
		dfs(edges[node][i]);
	}
}

int flag;

void chk(int node, int parent)
{
	if(visited[node] == 2){
		visited[node] = 1;
		return;
	}
	visited[node] = 2;
	if(edges[node].size()!=2){
		flag = 0;
		return;
	}
	int L = edges[node].size();
	for(int i=0; i<L; i++){
		if(edges[node][i]!=parent)
		chk(edges[node][i], node);
	}
	return;
}

int main()
{
	cin>>N>>M;
	for(int i=1; i<=M; i++){
		cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i=1; i<=N; i++)comp[i] = -1, done[i] = 0, visited[i]=0;
	for(int i=1; i<=N; i++){
		if(comp[i]==-1){
			dfs(i);
			component++;
		}
	}
	int ans = 0;
	for(int i=1; i<=N; i++){
		if(done[comp[i]] == 1)
			continue;
		flag = 1;
		chk(i, -1);
		ans+=(flag && visited[i] == 1);
		done[comp[i]] = 1;
	}
	cout<<ans<<endl;
	return 0;
}