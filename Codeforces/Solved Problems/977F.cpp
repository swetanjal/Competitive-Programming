#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5+5;

int N;
map < long long, int > H;
vector <int> edges[MAXN];

int DP[MAXN];

void print(int node)
{
	cout<<(node+1)<<" ";
	int L=edges[node].size();
	for(int i=0; i<L; i++){
		if(DP[edges[node][i]] == (DP[node]-1))
		{
			print(edges[node][i]);
		}
	}
}

void dfs(int node)
{
	if(DP[node]!=-1)return;
	int L = edges[node].size();
	for(int i=0; i<L; i++){
		dfs(edges[node][i]);
		DP[node] = max( DP[node], 1 + DP[edges[node][i]]); 
	}
	DP[node] = max(1, DP[node]);
}

int main()
{
	cin>>N;
	long long A[N];
	for(int i=0; i<N; i++)
		cin>>A[i];
	for(int i=N-1; i>=0; i--){
		if(H.find(A[i]+1)!=H.end()){
			//int L=H[A[i]+1].size();
			//for(int j=0; j<L; j++)
				edges[i].push_back(H[A[i]+1]);
		}
		//if(H.find(A[i])==H.end())
		H[A[i]] = i;
	}
	for(int i=0; i<N; i++)
		DP[i] = -1;
	int ANS = 0; int idx = -1;
	for(int i=0; i<N; i++){
		//if(DP[i]!=-1)
		//	continue;
		dfs(i);
		if(DP[i] > ANS){
			ANS = DP[i];
			idx = i;
		}
	}
	cout<<ANS<<endl;
	print(idx);
	cout<<endl;
	return 0;
}