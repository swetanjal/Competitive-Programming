#include <bits/stdc++.h>
using namespace std;
int N,M,S,D,u,v; char rate;
vector < pair <char , int> > edges[100005];
int dp[100005]; bool visited[100005];
void print()
{
	vector <int> V[2];
	int distance=dp[S]; int idx=0;
	V[idx].push_back(S); char already;
	for(int i=1; i<=N; i++)visited[i]=false;
	while(distance!=0)
	{
		already='z';
		int sz=V[idx].size();
		for(int i=0; i<sz; i++)
		{
			int node=V[idx][i];
			int L=edges[node].size();
			for(int j=0; j<L; j++)
			{
				int neighbour=edges[node][j].second;
				if(visited[neighbour]==false && dp[neighbour]==(distance-1))
				{
					if(edges[node][j].first<=already)
					{
						already=edges[node][j].first;
					}
				}
			}
		}
		for(int i=0; i<sz; i++)
		{
			int node=V[idx][i];
			int L=edges[node].size();
			for(int j=0; j<L; j++)
			{
				int neighbour=edges[node][j].second;
				if(visited[neighbour]==false && dp[neighbour]==(distance-1) && edges[node][j].first==already)
				{
					V[1-idx].push_back(neighbour);
					visited[neighbour]=true;
				}
			}
		}
		cout<<already;
		distance--;
		V[idx].clear();
		idx=1-idx;
	}
}
int main()
{
	cin>>N>>M;
	cin>>S>>D;
	for(int i=0; i<M; i++)
	{
		cin>>u>>rate>>v;
		edges[u].push_back(make_pair(rate,v));
		edges[v].push_back(make_pair(rate,u));
	}
	for(int i=1; i<=N; i++)
	{
		dp[i]=INT_MAX;
		visited[i]=false;
	}
	dp[D]=0;
	queue < pair <int , int> > Q;
	Q.push(make_pair(D,-1));
	while(Q.empty()==false)
	{
		pair <int , int > p1=Q.front();
		int node=p1.first;
		if(visited[node])
		{
			Q.pop();
			continue;
		}
		visited[node]=true;
		Q.pop();
		dp[node]=1+p1.second;
		int l=edges[node].size();
		for(int i=0; i<l; i++)
		{
			Q.push(make_pair(edges[node][i].second,dp[node]));
		}
	}
	print();
	cout<<"\n";
	return 0;
}
