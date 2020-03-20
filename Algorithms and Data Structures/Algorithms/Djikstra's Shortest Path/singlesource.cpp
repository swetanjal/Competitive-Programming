/*https://www.hackerrank.com/challenges/dijkstrashortreach/problem*/
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e5+5;
const long long INF = 1e9+9;
int T,N,M, u, v, C, source;
vector < pair <int, long long> > edges[MAXN];
long long dist[MAXN];

set < pair < long long , int > > S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>T;
	while(T--){
		cin>>N>>M;
		for(int i=1; i<=N; i++){
			dist[i] = INF;
			edges[i].clear();
		}
		for(int i=1; i<=M; i++){
			cin>>u>>v>>C;
			edges[u].push_back(make_pair(v,C));
			edges[v].push_back(make_pair(u,C));
		}
		cin>>source;
		S.clear();
		dist[source] = 0;
		S.insert(make_pair(0, source));
		while(S.empty() == false)
		{
			pair <long long, int> p = *(S.begin());
			S.erase(S.begin());
			int node = p.second;
			long long distance = p.first;
			int L=edges[node].size();
			for(int i=0; i<L; i++){
				pair <long long, int> adj = make_pair(dist[edges[node][i].first], edges[node][i].first);
				if (dist[edges[node][i].first] > distance + edges[node][i].second) {
					if(dist[edges[node][i].first]!=INF)S.erase(S.find(adj));
					dist[edges[node][i].first] = distance + edges[node][i].second;
					adj = make_pair(dist[edges[node][i].first], edges[node][i].first);
					S.insert(adj);
				}
			}
		}
		for(int i=1; i<=N; i++)
		{
			if(i == source)
				continue;
			if(dist[i] == INF)cout<<"-1 ";
			else cout<<dist[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}