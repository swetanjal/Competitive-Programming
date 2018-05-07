#include "bits/stdc++.h"
using namespace std;
const int MAXN = 105;
int N;
map <long long, int> H;
vector <int> edges[MAXN];
int indeg[MAXN];

vector <int> ANS;

void dfs(int node)
{
	ANS.push_back(node);
	int L=edges[node].size();
	for(int i=0; i<L; i++){
		dfs(edges[node][i]);
	}
}

int main()
{
	cin>>N;
	long long A[N];
	for(int i=0; i<N; i++){
		cin>>A[i];
		H[A[i]] = i;
	}
	for(int i=0; i<N; i++){
		if((A[i]%3)==0 && H.find(A[i]/3)!=H.end())
		{	
			edges[i].push_back(H[A[i]/3]);
			indeg[H[A[i]/3]]++;
		}
		if(H.find(A[i]*2)!=H.end())
		{	
			edges[i].push_back(H[A[i]*2]);
			indeg[H[A[i]*2]]++;
		}
	}
	int in0=0; int idx = -1;
	for(int i=0; i<N; i++){
		if(indeg[i]==0){
			in0++;
			idx = i;
		}
	}
	if(in0 == 1){
		dfs(idx);
	}
	if(ANS.size()==N){
		for(int i=0; i<N; i++)cout<<A[ANS[i]]<<" ";
	}
	else
		cout<<"-1";
	cout<<endl;
	return 0;
}