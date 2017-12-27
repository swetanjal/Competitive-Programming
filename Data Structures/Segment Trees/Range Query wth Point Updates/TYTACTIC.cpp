#include <bits/stdc++.h>
using namespace std;
int N,Q,u,v,timer=1;
long long S[100005];
bool visited[100005];
int st[100005],en[100005];
vector <int> edges[100005];
long long tree[4000005];
long long A[100005];
void build(int l, int r, int node)
{
	if(l==r){
		tree[node]=A[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,(2*node));
	build(mid+1,r,(2*node)+1);
	tree[node]=tree[2*node]+tree[(2*node)+1];
}
void update(int l, int r, int node, int up, long long val)
{
	if(l==r && l==up)
	{
		tree[node]=val;
		A[l]=val;
		return;
	}
	if(up<l || up>r)return;
	int mid=(l+r)/2;
	update(l,mid,(2*node),up,val);
	update(mid+1,r,(2*node)+1,up,val);
	tree[node]=tree[2*node]+tree[(2*node)+1];
}
long long query(int l, int r, int qlow, int qhigh, int node)
{
	if(l>qhigh || r<qlow)return 0;
	if(l>=qlow && r<=qhigh)return tree[node];
	int mid=(l+r)/2;
	return query(l,mid,qlow,qhigh,(2*node))+query(mid+1,r,qlow,qhigh,(2*node)+1);
}
void dfs(int node)
{
	if(visited[node])return;
	visited[node]=true;
	int l=edges[node].size();
	st[node]=timer;
	for(int i=0; i<l; i++)
	{
		if(visited[edges[node][i]]==true)continue;
		timer++;
		dfs(edges[node][i]);
	}
	en[node]=timer;
}
int main()
{
	cin>>N>>Q;
	for(int i=1; i<=N; i++)cin>>S[i];
	for(int i=1; i<N; i++)
	{
		cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i=1; i<=N; i++)
	{
		visited[i]=false;
	}
	dfs(1);
	for(int i=1; i<=N; i++)
	{
		A[st[i]]=S[i];
	}
	build(1,N,1);
	while(Q--)
	{
		char c;
		int vertex;
		long long value;
		cin>>c;
		cin>>vertex;
		if(c=='Q')
		{
			cout<<query(1,N,st[vertex],en[vertex],1)<<endl;
		}
		else
		{
			cin>>value;
			update(1,N,1,st[vertex],value);
		}
	}
	return 0;
}