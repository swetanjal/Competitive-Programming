/*
IOITC 2015
Problem: https://www.dropbox.com/s/fkg2u3y91dceetv/MadProf%20%28EN%29.pdf?dl=0
*/
#include <bits/stdc++.h>
using namespace std;
int N,Q,key,u,v;
long long val;
long long segtree[4000005];
long long lazy[4000005];
inline void propagate(int l, int r, int i)
{
	if(lazy[i]!=0)
	{
		segtree[i]+=((r-l+1)*lazy[i]);
		if(l!=r)
		{
			lazy[(2*i)+1]+=lazy[i];
			lazy[(2*i)+2]+=lazy[i];
		}
		lazy[i]=0;
	}
}
inline void update(int l, int r, int node, int qlow, int qhigh)
{
	propagate(l,r,node);
	if(l>qhigh || r<qlow)
	return;
	if(l>=qlow && r<=qhigh)
	{
		lazy[node]+=val;
		propagate(l,r,node);
		return;
	}
	int mid=(l+r)/2;
	update(l,mid,(2*node)+1,qlow,qhigh);
	update(mid+1,r,(2*node)+2,qlow,qhigh);
	segtree[node]=segtree[(2*node)+1]+segtree[(2*node)+2];
}
inline long long query(int l, int r, int node , int qlow, int qhigh)
{
	propagate(l,r,node);
	if(l>qhigh || r<qlow)return 0;
	if(l>=qlow && r<=qhigh)return segtree[node];
	int mid=(l+r)/2;
	return (query(l,mid,(2*node)+1,qlow,qhigh)+query(mid+1,r,(2*node)+2,qlow,qhigh));
}
int main()
{
	scanf("%d %d", &N, &Q);
	while(Q--)
	{
		scanf(" %d",&key);
		if(key==0)
		{
			scanf(" %d %d %lld",&u,&v,&val);
			
			update(1,N,0,u,v);
		}
		else
		{
			scanf(" %d %d",&u,&v);
			long long x=query(1,N,0,u,v);
			printf("%lld\n",x);
		}
	}
	return 0;
}
