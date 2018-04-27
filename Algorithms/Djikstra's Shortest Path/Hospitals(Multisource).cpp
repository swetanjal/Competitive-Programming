#include <bits/stdc++.h>
using namespace std;
int N,M,P,t,u,v;
long long X;
long long dist[100005];
set < pair < long long , int > > S;
vector < pair <int , long> > edges[100005];
int main()
{
	scanf("%d %d %d",&N,&M,&P);
	for(int i=1; i<=N; i++)
	{
		dist[i]=LONG_LONG_MAX;	
	}
	for(int i=1; i<=P; i++)
	{
		pair <long long , int> p1;
		scanf("%d ",&t);
		p1=make_pair(0,t);
		S.insert(p1);
		dist[t]=0;
	}
	for(int i=1; i<=M; i++)
	{
		pair < int , long long > p;
		scanf("%d %d %lld",&u,&v,&X);
		p=make_pair(v,X);
		edges[u].push_back(p);
		p=make_pair(u,X);
		edges[v].push_back(p);
	}
	while(S.empty()==false)
	{
		pair <long long , int> p=*(S.begin());
		S.erase(S.begin());
		int node=p.second;
		long long d=p.first;
		int l=edges[node].size();
		for(int i=0; i<l; i++)
		{
			pair <int , long long> y=edges[node][i];
			int child=y.first;
			long long d_t=y.second;
			if(dist[child]>(d+d_t))
			{
				if(dist[child]!=LONG_LONG_MAX)
				{
					pair <long long , int> chk;
					chk=make_pair(dist[child],child);
					S.erase(S.find(chk));
				}
				pair < long long , int> ins;
				ins=make_pair(d+d_t,child);
				S.insert(ins);
				dist[child]=d+d_t;
			}
		}
	}
	for(int i=1; i<=N; i++)
	{
		if(dist[i]!=0)
		{
			if(dist[i]==LONG_LONG_MAX)
			{
				dist[i]=-1;
				printf("%d %lld\n",i,dist[i]);
			}
			else printf("%d %lld\n",i,dist[i]);
		}
	}
	return 0;
}
