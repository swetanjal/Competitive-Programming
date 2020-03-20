#include <bits/stdc++.h>
using namespace std;
vector <int> edges[100005];
int N,u,v;
int C[100005];
bool visited[100005];
int ANS=0;
int dfs(int node, int color)
{
	if(visited[node])return 0;
	visited[node]=true;
	int tmp=0;
	if(color!=C[node])tmp++;
	int L=edges[node].size();
	for(int i=0; i<L; i++)
	{
		tmp+=dfs(edges[node][i],C[node]);
	}
	return tmp;
}
int main()
{
	cin>>N;
	for(int i=2; i<=N; i++)
	{
		cin>>u;
		edges[u].push_back(i);
		edges[i].push_back(u);
	}
	for(int i=1; i<=N; i++)
	{
		cin>>C[i];
	}
	for(int i=1; i<=N; i++)visited[i]=false;
	cout<<dfs(1,-1)<<endl;
	return 0;
}