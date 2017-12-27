#include <bits/stdc++.h>
using namespace std;
int N,M,u,v;
vector <int> edges[1000005];
bool visited[1000005][2]; long long ones, zeroes, both;
inline void dfs(int node, int mod)
{
	if(visited[node][mod])return;
	visited[node][mod]=true;
	if(mod==1)ones++;
	if(mod==0) zeroes++;
	if(visited[node][1] && visited[node][0])
	{
		ones--;
		zeroes--;
		both++;
	}
	int l=edges[node].size();
	for(int i=0; i<l; i++)
	{
		dfs(edges[node][i],1-mod);
	}
}
int main()
{
	scanf("%d %d", &N , &M);
	for(int i=1; i<=M; i++)
	{
		scanf("%d %d", &u , &v) ;
		u++; v++;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i=1; i<=N; i++)for(int j=0; j<=1; j++)visited[i][j]=false;
	long long ans=0;
	for(int i=1; i<=N; i++)
	{
		if(visited[i][0]==false && visited[i][1]==false)
		{
			ones=0; zeroes=0; both=0;
			dfs(i,0);
			ans=ans+(ones*ones)+(zeroes*zeroes)+(both*(both+ones+zeroes));
		}
		
	}
	printf("%lld\n",ans);
	return 0;
}
