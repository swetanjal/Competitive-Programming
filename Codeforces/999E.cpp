#include "bits/stdc++.h"
using namespace std;
const int MAXNM = 5005;
int N,M,S;
vector <int> edges[MAXNM];
int comp[MAXNM];
int indeg[MAXNM];
int paint = 1;
int u,v;

void dfs(int node)
{
	if(comp[node] == paint)
		return;
	int L = edges[node].size();
	comp[node] = paint;
	for(int i=0; i<L; i++)
		dfs(edges[node][i]);
}

void dfs1(int node)
{
	if(comp[node] == 0)return;
	int L = edges[node].size();
	indeg[node] = INT_MAX;
	comp[node] = 0;
	for(int i=0; i<L; i++)
		dfs1(edges[node][i]);

}

bool chk()
{
	for(int i=1; i<=N; i++)
		if(comp[i] == -1)return true;
	return false;
}

int main()
{
	cin>>N>>M>>S;
	for(int i=1; i<=M; i++)
	{
		cin>>u>>v;
		edges[u].push_back(v);
		indeg[v]++;
	}
	set <int> XXX;
	XXX.insert(0);

	for(int i=1; i<=N; i++)
		comp[i] = -1;
	dfs1(S);
	for(int i=1; i<=N; i++)
	{
		if(comp[i] == -1)
		{	
			dfs(i);
			paint++;
		}
	}
	for(int i=1; i<=N; i++)
	{
		XXX.insert(comp[i]);
	}
	cout<<(XXX.size()-1)<<endl;
	/*while(true)
	{
		int min_deg = INT_MAX;
		for(int i=1; i<=N; i++){
			if(comp[i] == -1)
				min_deg = min(min_deg, indeg[i]);
		}
		if(min_deg == INT_MAX)
			break;
		int done = 0;
		for(int i=1; i<=N; i++){
			if(indeg[i] == min_deg && comp[i] == -1)
			{	
				dfs(i);
				paint++;
				done = 1;
			}
		}
		if(done == 0)break;

	}
	cout<<(paint-1)<<endl;*/
	return 0;
}