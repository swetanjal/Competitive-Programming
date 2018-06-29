#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e6 + 5;
int N, M, K;

int blocked[MAXN];
long long A[MAXN];
int prev[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>N>>M>>K;
	for(int i=0; i<M; i++)
	{
		int tmp;
		cin>>tmp;
		blocked[tmp] = 1;
	}
	for(int i=1; i<=K; i++)
		cin>>A[i];
	if(blocked[0])
	{
		cout<<"-1\n";
		return 0;
	}
	int curr = 0;
	for(int i=0; i<=N; i++)
		prev[i] = -1;
	prev[0] = curr ; 
	for(int i=1; i<N; i++)
	{
		if(!blocked[i])
		{
			curr = i;
		}
		prev[i] = curr;
	}
	long long ret = LONG_LONG_MAX;
	for(int i=1; i<=K; i++)
	{
		int end = i;
		int posts  = 1;
		int last = 0;

		while(end < N && prev[end] != -1 && prev[end]>last)
		{
			//cout << last << " ";
			last = prev[end];
			end = prev[end] + i;
			
			posts++;
		}
		if(end >= N)
		{
			ret = min(ret, A[i] * posts);
		}
	}
	if(ret == LONG_LONG_MAX)
		cout<<"-1\n";
	else
		cout<<ret<<endl;
	return 0;
}
