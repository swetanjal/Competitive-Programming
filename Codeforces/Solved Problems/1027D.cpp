#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
vector <int> edges[MAXN];
vector <int> cycle;
vector <int> comp[MAXN];
long long C[MAXN];
int component[MAXN];
int visited[MAXN];
int paint;
int N;
void dfs(int node)
{
	if(visited[node] == 2)
		return;
	if(visited[node] == 1)
	{
		cycle.push_back(node);
		return;
	}
	visited[node] = 1;
	int L = edges[node].size();
	for(int i = 0; i < L; i++)
		dfs(edges[node][i]);
	visited[node] = 2;
}
int stop;
void dfs2(int node)
{
	if(component[node] != -1)
		return;
	component[node] = paint;
	int L = edges[node].size();
	for(int i = 0; i < L; i++)
	{
		dfs2(edges[node][i]);
	}
}

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> C[i];
	for(int i = 1; i <= N; i++)
	{
		int tmp;
		cin >> tmp;
		edges[i].push_back(tmp);
	}
	for(int i = 1; i <= N; i++)
	{
		visited[i] = 0;
		component[i] = -1;
	}
	for(int i = 1; i <= N; i++){
		if(visited[i] == 0)
			dfs(i);
	}
	int L = cycle.size();
	//cout << cycle[0] << " " << cycle[1] << endl;
	for(int i = 0; i < L; i++){
		if(component[cycle[i]] == -1){
			dfs2(cycle[i]);
		}
		paint++;
	}
	for(int i = 1; i <= N; i++){
		if(component[i] != -1)
			comp[component[i]].push_back(C[i]);
	}
	long long ans = 0;
	for(int i = 0; i < N; i++)
	{
		sort(comp[i].begin(), comp[i].end());
		if(comp[i].size() > 0)
			ans = ans + comp[i][0];
	}
	cout << ans << endl;
	return 0;
}