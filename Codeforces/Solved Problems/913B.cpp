#include "bits/stdc++.h"
using namespace std;
int N;
int flag=1;
vector <int> edges[100005];
int leaf[100005];
void dfs(int node)
{
	int L=edges[node].size();
	if(L==0)return;
	int cnt=0;
	for(int i=0; i<L; i++)
	{
		if(leaf[edges[node][i]])cnt++;
	}
	if(cnt<3){
		flag=0;
		return;
	}
	for(int i=0; i<L; i++)
		dfs(edges[node][i]);
}

int main()
{
	cin>>N;
	for(int i=2; i<=N; i++)
	{
		int tmp;
		cin>>tmp;
		edges[tmp].push_back(i);
	}
	for(int i=1; i<=N; i++)
	{
		if(edges[i].size()==0)leaf[i]=1;
	}
	dfs(1);
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}