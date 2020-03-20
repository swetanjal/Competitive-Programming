#include <bits/stdc++.h>
using namespace std;
int N;
vector <int> edges[100005];
int H[100005],F[100005];
bool visited[100005];
int connected[100005];
int node_of_H[100005];
int flood=0;
void dfs(int node)
{
	if(visited[node])return;
	visited[node]=true;
	connected[node]=flood;
	int L=edges[node].size();
	for(int i=0; i<L; i++)
	{
		dfs(edges[node][i]);
	}
}
int main()
{
	cin>>N;
	for(int i=1; i<=N; i++)
	{
		cin>>H[i];
		node_of_H[H[i]]=i;
	}
	for(int i=1; i<=N; i++)
	{
		cin>>F[i];
		int node1=i-F[i];
		if(node1>=1)
		{
			edges[i].push_back(node1);
			edges[node1].push_back(i);
		}
		node1=i+F[i];
		if(node1<=N)
		{
			edges[i].push_back(node1);
			edges[node1].push_back(i);
		}
	}
	for(int i=1; i<=N; i++)visited[i]=false;
	for(int i=1; i<=N; i++)
	{
		if(visited[i]==false)
		{
			dfs(i);
			flood++;
		}
	}
	int flag=1;
	for(int i=1; i<=N; i++)
	{
		if(connected[i]==connected[node_of_H[i]])
		continue;
		flag=0;
		break;
	}
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
