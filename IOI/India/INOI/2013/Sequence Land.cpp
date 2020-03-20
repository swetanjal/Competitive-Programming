#include <bits/stdc++.h>
using namespace std;
int N,K,tmp;
struct element{
	int n;
	vector <int> x;
};
element A[305];
vector <int> edges[305];
map <int, int> hash;
bool visited[305];
int ans=0;
void dfs(int node)
{
	if(visited[node])return;
	ans++;
	visited[node]=true;
	int l=edges[node].size();
	for(int i=0; i<l; i++)
	{
		dfs(edges[node][i]);
	}
}
bool connected(int i, int j)
{
	hash.clear();
	int cnt=0;
	for(int l=0; l<A[i].n; l++)hash[A[i].x[l]]=1;
	for(int l=0; l<A[j].n; l++)if(hash.find(A[j].x[l])!=hash.end())cnt++;
	if(cnt>=K)return true;
	return false;
}
int main()
{
	cin>>N>>K;
	for(int i=0; i<N; i++)
	{
		cin>>A[i].n;
		for(int j=0; j<A[i].n; j++)
		{
			cin>>tmp;
			A[i].x.push_back(tmp);
		}
	}
	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			if(connected(i,j)){
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		}
	}
	for(int i=0; i<305; i++)visited[i]=false;
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
