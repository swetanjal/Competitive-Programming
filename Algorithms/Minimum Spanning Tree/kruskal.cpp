#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5+5;
const int MAXM = 9e6+6;
struct edge{
	int u;
	int v;
	int cost;
};

int N,M, U, V, C;
edge A[MAXM];
int parent[MAXN];
int sz[MAXN];

int root(int node)
{
	if(parent[node] == node)return node;
	return parent[node] = root(parent[node]);
}

void _union(int a, int b)
{
	if(a==b)return;
	a = root(a);
	b = root(b);
	if(sz[a]<sz[b]){
		sz[b]+=sz[a];
		parent[a] = parent[b];
	}
	else
	{
		sz[a]+=sz[b];
		parent[b] = parent[a];
	}
}

bool comp(edge a, edge b)
{
	return a.cost<b.cost;
}

int main()
{
	cin>>N>>M;
	for(int i=0; i<M; i++){
		cin>>U>>V>>C;
		A[i].u = U;
		A[i].v = V;
		A[i].cost = C;
	}
	sort(A, A+M, comp);
	long long ret = 0;
	for(int i=1; i<=N; i++)sz[i] = 1, parent[i] = i;
	for(int i=0; i<M; i++){
		U = A[i].u;
		V = A[i].v;
		C = A[i].cost;
		if(root(U)==root(V))continue;
		_union(U,V);
		ret+=C;
	}
	cout<<ret<<endl;
	return 0;
}