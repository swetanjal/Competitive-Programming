#include "bits/stdc++.h"
using namespace std;

map <long long, int> H;

int main()
{
	int N;
	cin>>N;
	long long A[N];
	for(int i=0; i<N; i++)
	{
		cin>>A[i];
	}
	set <long long> S;
	long long cnt[N];
	for(int i = N-1; i>=0; i--)
	{
		S.insert(A[i]);
		cnt[i] = S.size();
	}
	long long ret = 0;
	for(int i=0; i<N-1; i++)
	{
		if(H.find(A[i]) == H.end()){
			ret += cnt[i+1];
			H[A[i]] = 1;
		}
	}
	cout<<ret<<endl;
	return 0;
}