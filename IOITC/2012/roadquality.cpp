/*
IOITC 2012
Problem: 
*/
#include <bits/stdc++.h>
using namespace std;
struct element{
	int node1;
	int node2;
	long long q;
	long long l;
};
int N,M,u,v;
long long q,l;
element A[1000005];
int sz[5005]; int parent[5005];
int root(int x)
{
	if(parent[x]==x)return x;
	return parent[x]=root(parent[x]);
}
void union_(int x, int y)
{
	if(x==y)return;
	int i=root(x);
	int j=root(y);
	if(sz[i]<sz[j])
	{
		parent[i]=j;
		sz[j]+=sz[i];
	}
	else
	{
		parent[j]=i;
		sz[i]+=sz[j];
	}
}
bool compare1(element a, element b)
{
	return (a.q>b.q);
}
bool compare2(element a, element b)
{
	return (a.l<b.l);
}
int main()
{
	cin>>N>>M;
	for(int i=0; i<M; i++)
	{
		cin>>A[i].node1>>A[i].node2>>A[i].q>>A[i].l;
	}
	sort(A,A+M,compare1);
	for(int i=0; i<N; i++)
	{
		sz[i]=1;
		parent[i]=i;
	}
	long long quality=LONG_LONG_MAX; long long length=0;
	int cnt=0;
	for(int k=0; k<M; k++)
	{
		int i=root(A[k].node1);
		int j=root(A[k].node2);
		if(i==j)continue;
		cnt++;
		quality=min(quality,A[k].q);
		union_(A[k].node1,A[k].node2);
	}
	if(cnt!=(N-1))
	{
		cout<<"-1\n";
		return 0;
	}
	else cout<<quality<<" ";
	sort(A,A+M,compare2);
	for(int i=0; i<N; i++)
	{
		sz[i]=1;
		parent[i]=i;
	}
	for(int k=0; k<M; k++)
	{
		int i=root(A[k].node1);
		int j=root(A[k].node2);
		if(i==j)continue;
		if(A[k].q<quality)continue;
		length+=A[k].l;
		union_(A[k].node1,A[k].node2);
	}
	cout<<length<<endl;
	return 0;
}
