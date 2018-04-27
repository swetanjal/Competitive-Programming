#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5+5;

int N,M;

vector < pair <int , int> > edges[MAXN];
priority_queue < pair <int, int> , vector < pair <int, int> > , greater < pair <int, int> > >P;
int exists[MAXN], curr, u, v, cost;

int main()
{
	cin>>N>>M;
	for(int i=1; i<=M; i++){
		cin>>u>>v>>cost;
		edges[u].push_back(make_pair(v,cost));
		edges[v].push_back(make_pair(u,cost));
	}
	P.push(make_pair(0,1));
	curr = 0;
	long long ret = 0;
	while(P.empty()==false)
	{
		pair <int , int> p = P.top();
		P.pop();
		
		int node = p.second;
		if(exists[node])continue;
		curr++;
		ret += p.first;
		exists[node] = 1;
		int L = edges[node].size();
		for(int i=0; i<L; i++){
			if(exists[edges[node][i].first] != 1)
			{
				P.push(make_pair(edges[node][i].second, edges[node][i].first));
			}
		}
	}
	cout<<ret<<endl;
	return 0;
}