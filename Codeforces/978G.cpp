#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e2 + 5;

int N,M;
int A[MAXN];
pair < int, pair < int, int > > D[MAXN];

int main()
{
	cin>>N>>M;
	for(int i=0; i<M; i++)cin>>D[i].first>>D[i].second.first>>D[i].second.second;
	for(int i=1; i<=N; i++)
	{
		//Check whether today is any exam.
		int yes = 0;
		for(int j=0; j<M; j++)
		{
			if(D[j].second.first == i && D[j].second.second == 0)
			{
				yes = 1;
				A[i] = M+1;
			}
		}
		if(yes)continue;
		int earliest = INT_MAX; int idx = -1;
		for(int j=0; j<M; j++){
			if(i>=D[j].first && i<D[j].second.first && D[j].second.second>0)
			{
				if(earliest>D[j].second.first){
					earliest = D[j].second.first;
					idx = j;
				}
			}
		}
		if(idx==-1)A[i] = 0;
		else{
			A[i] = (idx+1);
			D[idx].second.second--;
		}
	}
	int impossible = 0;
	for(int i=0; i<M; i++){
		if(D[i].second.second>0)
		{
			impossible = 1;
			break;
		}
	}
	if(impossible)cout<<"-1\n";
	else
	{
		for(int i=1; i<=N; i++)
			cout<<A[i]<<" ";
		cout<<endl;
	}
	return 0;
}