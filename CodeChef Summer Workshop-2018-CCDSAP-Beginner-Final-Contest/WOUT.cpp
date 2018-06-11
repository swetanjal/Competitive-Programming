#include "bits/stdc++.h"
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,H;
		cin>>N>>H;
		long long int A[N + 2];
		for(int i=0; i<=(N + 1); i++)
			A[i] = 0;
		for(int i=1; i<=N; i++)
		{
			int l,h;
			cin>>l>>h;
			int low = N - h;
			int high = N - l;
			A[low]++;
			A[high + 1]--;
		}
		for(int i=1; i<=(N+1); i++)
			A[i] += A[i-1];
		for(int i=1; i<=(N+1); i++)
			A[i] += A[i-1];
		long long ret = LONG_LONG_MAX;
		for(int i=H; i<=N; i++) 
			ret = min(ret, (H*1LL*N) - (A[i] - A[i - H]));
		cout<<ret<<endl;
	}
	return 0;
}