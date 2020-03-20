#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
	int N,K;
	cin>>N>>K;
	stack < pair <int, int> > S;
	long long next_lesser[N];
	for(int i=0; i<N; i++)
		next_lesser[i] = -1;
	for(int i=0; i<N; i++)
	{
		long long u;
		cin>>u;
		while(S.empty() == false && S.top().first > u)
		{
			next_lesser[S.top().second] = i;
			S.pop();
		}
		S.push(make_pair(u,i));
	}
	long long ret = 1;
	for(int i=0; i<N; i++)
	{
		if(next_lesser[i] == -1)
			continue;
		ret = (ret * (next_lesser[i] - i + 1))%MOD;
	}
	cout<<ret<<endl;
	return 0;
}