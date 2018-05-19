#include "bits/stdc++.h"
using namespace std;
const int MAXN = 3e5+ 5;

int level[MAXN];
int N,X,Y, u, v;
vector <int> edges[MAXN];
int exists_X[MAXN];
int exists_Y[MAXN];
int sub_sz[MAXN];

void dfs(int node, int parent, int depth)
{
	int L = edges[node].size();
	level[node] = depth;
	if(node==X)
		exists_X[node] = 1;
	else
		exists_X[node] = 0;
	if(node == Y)
		exists_Y[node] = 1;
	else
		exists_Y[node] = 0;
	sub_sz[node] = 1;
	for(int i=0; i<L; i++){
		if(edges[node][i]!=parent){
			dfs(edges[node][i], node, depth + 1);
			exists_X[node]=exists_X[node] | exists_X[edges[node][i]];
			exists_Y[node]=exists_Y[node] | exists_Y[edges[node][i]];
			sub_sz[node] += sub_sz[edges[node][i]];
		}
	}
}

int main()
{
	cin>>N>>X>>Y;
	for(int i=1; i<N; i++){
		cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1, -1, 0);
	//X is first and then Y
	//Case 1
	if(exists_Y[X]==1){
		//Y is located in subtree of X
		int sp_vertex = -1;
		int L = edges[X].size();
		for(int i=0; i<L; i++){
			if(exists_Y[edges[X][i]] && level[edges[X][i]]>level[X])
			{
				sp_vertex = i;
				break;
			}
		}
		int sz = sub_sz[edges[X][sp_vertex]];
		long long ans = ((sub_sz[1] - sz) * 1LL * sub_sz[Y]);
		
		ans = (N*1LL*(N-1)) - ans; 
		cout<<ans<<endl;
	}
	else if(exists_X[Y]==1){
		//X is located in subtree of Y
		int sp_vertex = -1;
		int L = edges[Y].size();
		for(int i=0; i<L; i++){
			if(exists_X[edges[Y][i]] && level[edges[Y][i]]>level[Y])
			{
				sp_vertex = i;
				break;
			}
		}
		int sz = sub_sz[edges[Y][sp_vertex]];
		long long ans = ((sub_sz[1] - sz) * 1LL * sub_sz[X]);
		
		ans = (N*1LL*(N-1)) - ans; 
		cout<<ans<<endl;
	}
	else
	{
		//different subtrees
		long long ans = sub_sz[X]*1LL*sub_sz[Y];
		ans = (N*1LL*(N-1)) - ans;
		cout<<ans<<endl;
	}
	return 0;
}