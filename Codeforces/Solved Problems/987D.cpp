#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5 + 5;
int N,M,K,S;
vector <int> edges[MAXN];
vector <int> city[105];
int cost[MAXN][105];

void solve(int id)
{
	queue <int> Q;
	queue <int> level;
	int L = city[id].size();
	bool visited[MAXN];
	for(int i=1; i<=N; i++)
		visited[i] = false;
	for(int i=0; i<L; i++)
	{
		Q.push(city[id][i]);
		level.push(0);
		//visited[city[id][i]] = true;
	}
	while(Q.empty()==false)
	{
		int top = Q.front();
		int lev = level.front();
		Q.pop();
		visited[top] = true;
		level.pop();
		int l = edges[top].size();
		cost[top][id] = min(lev, cost[top][id]);
		for(int i=0; i<l; i++)
		{
			if(visited[edges[top][i]] == false)
			{
				Q.push(edges[top][i]);
				level.push(lev + 1);
			}
		}
	}
}

int main()
{
	cin>>N>>M>>K>>S;
	for(int i=1; i<=N; i++)
	{
		int tmp;
		cin>>tmp;
		city[tmp].push_back(i);
	}
	for(int i=1; i<=N; i++)
		for(int j=1; j<=K; j++)
			cost[i][j] = INT_MAX;
	for(int i=1; i<=M; i++)
	{
		int u,v;
		cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i=1; i<=K; i++)
		solve(i);
	for(int i=1; i<=N; i++)
	{
		vector <int> X;
		for(int j = 1; j<=K; j++)
			X.push_back(cost[i][j]);
		sort(X.begin(), X.end());
		long long sum = 0;
		for(int j=0; j<S; j++)
			sum += X[j];
		cout<<sum<<" ";
	}
	cout<<endl;
	return 0;
}